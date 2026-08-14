CC = gcc
CFLAGS = -Wall -Wextra -g

all: sbuf_test

sbuf_test: main.o sbuf.o
	$(CC) $(CFLAGS) -o sbuf_test main.o sbuf.o

main.o: main.c sbuf.h
	$(CC) $(CFLAGS) -c main.c

sbuf.o: sbuf.c sbuf.h
	$(CC) $(CFLAGS) -c sbuf.c

clean:
	rm -f *.o sbuf_test