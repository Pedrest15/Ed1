all: trab02

run:
	./trab02

trab02: main.o ldes.o
	gcc -o trab02 main.o ldes.o

main.o: main.c
	gcc -o main.o -c main.c

ldes.o: ldes.c
	gcc -o ldes.o -c ldes.c

clean:
	rm *.o trab02

zip: 
	zip trab02.zip *.c *.h Makefile

rmzip:
	rm *.zip