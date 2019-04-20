CC = g++

CFLAGS = -c -Wall

all: run

run: main.o
	$(CC) main.o -o run

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

.PHONY : clean
clean:
	rm -rf *.o run
