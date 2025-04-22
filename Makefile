CC = gcc
CFLAGS = -Wall -g
OBJ = hash_table.o test.o

all: test

hash_table.o: hash_table.c hash_table.h
	$(CC) $(CFLAGS) -c hash_table.c

test.o: test.c hash_table.h
	$(CC) $(CFLAGS) -c test.c

test: $(OBJ)
	$(CC) $(CFLAGS) -o test $(OBJ)

run: test
	./test

clean:
	rm -f *.o test
