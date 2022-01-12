all: FilaBancoEstat

run:
	./FilaBancoEstat 

FilaBancoEstat: main.o ListaEstatica.o
	gcc -g -o FilaBancoEstat main.o ListaEstatica.o

main.o: main.c
	gcc -g -o main.o -c main.c

ListaEstatica.o: ListaEstatica.c
	gcc -g -o ListaEstatica.o -c ListaEstatica.c

clean:
	rm *.o FilaBancoEstat

zip: FilaBancoEstat
	zip filabanco *.c *.h Makefile

rmzip:
	rm *.zip
