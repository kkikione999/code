

all: main.o sqstack.o
	gcc main.o sqstack.o -o all

main.o: main.c
	gcc main.c -Wall -g -c -o main.o

sqstack.o: sqstack.c
	gcc sqstack.c -Wall -g -c -o sqstack.o

clean:
	rm *.o all -rf
