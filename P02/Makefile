all: prog_p2

run:
	./prog_p2

prog_p2: main.o avravl.o
	gcc -o prog_p2 main.o avravl.o

main.o: main.c
	gcc -o main.o -c main.c

avravl.o: avravl.c
	gcc -o avravl.o -c avravl.c

clean:
	rm *.o

zip: prog_p2
	zip p2.zip *.c *.h Makefile

rmzip: 
	rm *.zip
