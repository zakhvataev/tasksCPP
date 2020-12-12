CC=g++
CFLAGS = -c

all: clean main.o tree_exp.o Parser.o
	$(CC) main.o tree_exp.o Parser.o -o start

clear:
	clear

test:
	./start

main.o:
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *.o start
