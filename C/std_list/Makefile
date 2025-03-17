#帮我编写makefile
CC = gcc
CFLAGS = -g -Wall
TARGET = main
OBJS = main.o list.o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

list.o: list.c
	$(CC) $(CFLAGS) -c list.c
	
clean:
	rm -f $(OBJS) $(TARGET)



