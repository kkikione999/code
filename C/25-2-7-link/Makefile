CC=gcc
OBJS=main.o node.o
CFLAGS+=-Wall -g -c

node: main.o node.o
	$(CC) $(OBJS) -o node

main.o: main.c
	$(CC) $^ $(CFLAGS) -o $@

node.o: node.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm -f *.o node