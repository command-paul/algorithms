CC=gcc
CFLAGS= -Wall -g -c -o
OBJECTS = src/main.o src/sort.o src/search.o src/misc.o
TARGETS = csd201 
TESTS = tests/sort.o

all: $(TARGETS)

src/sort.o:
	$(CC) $(CFLAGS) src/sort.o src/sort.c

src/search.o:
	$(CC) $(CFLAGS) src/search.o src/search.c

src/misc.o:
	$(CC) $(CFLAGS) src/misc.o src/misc.c

src/main.o: src/sort.o src/search.o src/misc.o
	$(CC) $(CFLAGS) src/main.o src/main.c

csd201: $(OBJECTS)
	$(CC) -o csd201 $(OBJECTS)

test: $(OBJECTS)
	$(CC) $(CFLAGS) tests/sort.o tests/sort.c 
	$(CC) -o testexec $(TESTS) src/sort.o
clean:
	rm -f *.o
	rm csd201
	rm src/*.o
	rm tests/*.o
	rm testexec
