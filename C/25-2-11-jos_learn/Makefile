OBJS=main.o list.o
CC=gcc
CFLAGS+=-Wall -g -c

mian: main.o list.o
	gcc mian.o list.o -o main

main.o:
	gcc main.c $(CFLAGS) -o mian.o

list.o:
	gcc list.c $(CFLAGS) -o list.o

clean:
	rm *.o mian -rf