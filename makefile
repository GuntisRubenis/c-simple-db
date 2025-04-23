CC = gcc
CFLAGS = -Wall -Wextra -std=c99

db: database.o part.o
	$(CC) $(CFLAGS) -o db database.o part.o

database.o: database.c part.h
	$(CC) $(CFLAGS) -c database.c

part.o: part.c
	$(CC) $(CFLAGS) -c part.c
