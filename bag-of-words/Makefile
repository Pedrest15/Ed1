all: prog

run:
	./prog

prog: main.o avravl.o ldes.o
	gcc -o prog main.o avravl.o ldes.o

main.o: main.c
	gcc -o main.o -c main.c

avravl.o: avravl.c
	gcc -o avravl.o -c avravl.c

ldes.o: ldes.c
	gcc -o ldes.o -c ldes.c

clean:
	rm *.o prog

zip:
	zip prog *.c *.h Makefile *.txt

rmzip: 
	rm *.zip