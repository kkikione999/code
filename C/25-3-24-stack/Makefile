CC = gcc
CFLAGS = -Wall -g -c
OBJS = main.o llist.o stack.o

all:$(OBJS)
	$(CC) $^ -o $@

main.o:main.c
	$(CC) $^ $(CFLAGS) -o $@

llist.o:llist.c
	$(CC) $^ $(CFLAGS) -o $@

stack.o:stack.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	$(RM) *.o all -r

