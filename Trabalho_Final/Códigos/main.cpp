#include <stdio.h>
#include <wiringPi.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include "MJPEGWriter.h"
#include <tgbot/tgbot.h>

pthread_t streamer, notification, telegram_tbot, tpisca_led;
using namespace std;
int control,flag=0;
MJPEGWriter test(8080);

void* pisca_led(void*){

	while(1)
		{
			digitalWrite(1, HIGH); // liga o pino 1
			delay(1000);           // espera 1 segundo
			digitalWrite(1, LOW);  // desliga o pino 1
			delay(1000);		 //  espera 1 segundo
		}
	return NULL;

}

void* push_notification(void*){

	system("curl -s -X POST https://api.telegram.org/XXXXXXXX/sendMessage -d chat_id=XXXXXXX -d text='SmartDoorBell - Acionamento da Campainha'");
	delay(20);
	system("curl -s -X POST 'https://api.telegram.org/XXXXXXXX/sendPhoto' -F chat_id=-XXXXXXX -F photo='@/home/pi/MJPEGWriter/FotoSmartDoorbell.jpg'");
	return NULL;
}

void* streaming(void*)
{	
printf("Streaming Disponivel\n");

    VideoCapture cap;
    bool ok = cap.open(0);
    if (!ok)
    {
        printf("no cam found ;(.\n");
        pthread_exit(NULL);
    }
    
    Mat frame;
    cap >> frame;
    test.write(frame);
    frame.release();
    test.start();

    while(cap.isOpened() && (control == 0))
    {
    	cap >> frame; 
    	test.write(frame); 
    	frame.release();
    }
    
    printf("Fim do Loop");
    cap.release();
    
    //exit(0);
    return NULL;
}

void* telegram_bot(void*){

	TgBot::Bot bot("XXXXXXXXX"); #Inserir o TOKEN do Bot

	bot.getEvents().onCommand("capture", [&bot](TgBot::Message::Ptr message) {
	bot.getApi().sendMessage(message->chat->id, "Uma foto está sendo capturada e chegará em breve.");
    system("raspistill -o /home/pi/MJPEGWriter/FotoSmartDoorbell.jpg");
   	system("curl -s -X POST 'https://api.telegram.org/XXXXXXXXX/sendPhoto' -F chat_id=<XXXXXX> -F photo='@/home/pi/MJPEGWriter/FotoSmartDoorbell.jpg'");
    });

    bot.getEvents().onCommand("call", [&bot](TgBot::Message::Ptr message) {
    bot.getApi().sendMessage(message->chat->id, "Ligação iniciada.");
    system("python sim800_call.py");
    });

	bot.getEvents().onCommand("call_flag", [&bot](TgBot::Message::Ptr message) {
    flag = 1;
    bot.getApi().sendMessage(message->chat->id, "Modo Mensagem de Voz Desligado");
    bot.getApi().sendMessage(message->chat->id, "Modo Ligação Ligado");
    });

	bot.getEvents().onCommand("rec_flag", [&bot](TgBot::Message::Ptr message) {
    flag = 0;
    bot.getApi().sendMessage(message->chat->id, "Modo Ligação Desligado");
    bot.getApi().sendMessage(message->chat->id, "Modo Mensagem de Voz Ligado");
    });

    bot.getEvents().onCommand("stream_on", [&bot](TgBot::Message::Ptr message) {
    control = 0;
    bot.getApi().sendMessage(message->chat->id, "Stream Disponivel");
    pthread_create(&streamer, NULL, streaming, NULL);
    });

    bot.getEvents().onCommand("stream_off", [&bot](TgBot::Message::Ptr message) {
    control = 1;
    bot.getApi().sendMessage(message->chat->id, "Stream Indisponivel");
    });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }

return NULL;
}

void tratamento_alarme(int sig)
{	
	pthread_cancel(tpisca_led);	
	control = 1;
	//cap.release();
	printf("Streaming Finalizado\n");

	if(flag==0){
		digitalWrite(1, HIGH); // liga o pino 1
		printf("Gravando Mensagem de Voz\n");
		system("arecord -D plughw:1 --duration=10 -f cd -vv ~/MJPEGWriter/rectest.wav");
		delay(10500);
		digitalWrite(1, LOW);  // desliga o pino 1
		system("curl -s -X POST https://api.telegram.org/XXXXXXXXX/sendAudio -F chat_id=<XXXXXXX> -F audio='@/home/pi/MJPEGWriter/rectest.wav'");
	}

	if(flag==1){
		system("python sim800_call.py");
	}

}

int main()
{
	pthread_create(&telegram_tbot, NULL, telegram_bot, NULL);
	wiringPiSetup();            // inicia biblioteca wiringPi
	pinMode(0, INPUT);         // configura pino 7 como entrada
	pinMode(1, OUTPUT);
	pullUpDnControl(0, PUD_UP); // configura resistor pull-up no pino 7
	signal(SIGALRM, tratamento_alarme);

	while(1)
	{
		if(digitalRead(0) == LOW)        // detecta se a chave foi pressionada
		{	
			delay(20);
			control = 0;
			pthread_create(&tpisca_led, NULL, pisca_led, NULL);
			system("raspistill -o /home/pi/MJPEGWriter/FotoSmartDoorbell.jpg");
			pthread_create(&notification, NULL, push_notification, NULL);
			//pthread_join(notification,NULL);
			pthread_create(&streamer, NULL, streaming, NULL);
			alarm(20);
			while(digitalRead(0) == LOW); // aguarda enquato chave ainda esta pressionada			
			delay(20);
		}	
	}
return 0;
}
