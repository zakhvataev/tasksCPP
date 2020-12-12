CC=g++
CFLAGS = -c

all: clean main.o BitSet.o
	$(CC) main.o BitSet.o -o start

test:
	./start

main.o:
	$(CC) $(CFLAGS) main.cpp

BitSet.o:
	$(CC) $(CFLAGS) BitSet.cpp

clean:
	rm -rf *.o start
