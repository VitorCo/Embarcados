Final: main.o Num_Caracs.o
	gcc $(CFLAGS) -o Final main.o Num_Caracs.o
main.o: main.c Num_Caracs.h
	gcc $(CFLAGS) -c main.c
Num_Caracs.o: Num_Caracs.c Num_Caracs.h
	gcc $(CFLAGS) -c Num_Caracs.c
clean:
	rm -f *.o Final
