CC=gcc
CFLAGS= -Wall -Werror -g -c -o
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

packages:
	sudo apt-get install freeglut3 freeglut3-dev
	sudo apt-get install libsoil-dev

graph:
	$(CC) -c -fpic -o src/graph.o src/graph.c -lglut -lSOIL -lGL -lGLU -lm
	$(CC) -shared -o src/libgraph.so src/graph.o
	sudo cp src/libgraph.so /usr/lib
	sudo chmod 0755 /usr/lib/libgraph.so
	sudo ldconfig

makegraph:
	$(CC) -o csd201 src/testgraph.c -lgraph -lSOIL -lglut -lGL -lGLU -lm

clean:
	rm -f *.o
	rm csd201
	rm src/*.o
	rm tests/*.o
	rm testexec

.PHONY: all packages
