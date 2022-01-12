all: trab03

run:
	./trab03

trab03: main.o arvbin.o
	gcc -o trab03 main.o arvbin.o

main.o: main.c
	gcc -o main.o -c main.c

arvbin.o: arvbin.c
	gcc -o arvbin.o -c arvbin.c

clean:
	rm *.o
	rm trab03

zip: trab03
	zip trab03.zip *.c *.h Makefile

rmzip:
	rm *.zip