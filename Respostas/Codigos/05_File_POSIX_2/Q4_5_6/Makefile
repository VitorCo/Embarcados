cat_falsificado: main.o bib_arqs.o
	gcc $(CFLAGS) -o cat_falsificado main.o bib_arqs.o
main.o: main.c bib_arqs.h
	gcc $(CFLAGS) -c main.c
bib_arqs.o: bib_arqs.c bib_arqs.h
	gcc $(CFLAGS) -c bib_arqs.c
clean:
	rm -f *.o cat_falsificado
