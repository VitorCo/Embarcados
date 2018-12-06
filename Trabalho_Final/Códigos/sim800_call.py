import serial
import RPi.GPIO as GPIO      
import os, time

# Enable Serial Communication
Serial = serial.Serial("/dev/ttyS0", baudrate=9600, timeout=2)
data=""

def gsmInit():
    print ("Finding Module")
    time.sleep(1)
    while 1:
        data=""
        Serial.write("AT\r");
        data=Serial.read(10)
        print data
        r=data.find("OK")
        if r>=0:
            break
        time.sleep(0.5)
        
    while 1:
        data=""
        Serial.write("AT+CLIP=1\r");
        data=Serial.read(10)
        print data
        r=data.find("OK")
        if r>=0:
            break
        time.sleep(0.5)
        
 
    print("Finding Network")
    time.sleep(1)
    while 1:
        data=""
        Serial.flush()
        Serial.write("AT+CPIN?\r");
        data=Serial.read(30)
        print data
        r=data.find("READY")
        if r>=0:
            break
        time.sleep(0.5)
    
    print("Finding Operator")
    time.sleep(1)
    while 1:
        data=""
        Serial.flush()
        Serial.read(20)
        Serial.write("AT+COPS?\r");
        data=Serial.read(40)
        #print data
        r=data.find("+COPS:")
        if r>=0:
            l1=data.find(",\"")+2
            l2=data.find("\"\r")
            operator=data[l1:l2]
            time.sleep(3)
            print operator
            break;
        time.sleep(0.5)
    Serial.write("AT+CMGF=1\r");
    time.sleep(0.5)
   # Serial.write("AT+CNMI=2,2,0,0,0\r");
   # time.sleep(0.5)
    Serial.write("AT+CSMP=17,167,0,0\r");
    time.sleep(0.5)
    
    while 1:
        data=""
        Serial.write('AT+CMIC? \n\r');
        data=Serial.read(100)
        print data
        r=data.find("OK")
        if r>=0:
            break
        
def call():
    print "Call"
    time.sleep(2)
    while 1:
	    Serial.write('ATD985456016;\r\n')
	    data=""
	    time.sleep(2)
	    data=Serial.read(100)
	    print data
	    l=data.find("OK")
	    if l>=0:
	        print("Calling.....")
	        time.sleep(30)
	        return
	    #l=data.find("Error")
	    #if l>=0:
	    else:
	        print("Error")
	        time.sleep(10)
	        return
 
# Transmitting AT Commands to the Modem
# '\r\n' indicates the Enter key
#gsmInit() #Comandos AT de teste para verificar diferentes parâmetros do módulo.
call()

