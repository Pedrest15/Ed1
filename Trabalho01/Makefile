all: trab01
	
run:
	./trab01

trab01: main.o ldes.o 
	gcc -o trab01 main.o ldes.o 

main.o: main.c
	gcc -o main.o -c main.c

ldes.o: ldes.c
	gcc -o ldes.o -c ldes.c

clean:
	rm *.o trab01