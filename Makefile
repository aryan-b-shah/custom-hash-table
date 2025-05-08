CC = g++
CFLAGS = -std=c++11

encoder: main.o hash.o
	$(CC) $(CFLAGS) -o encoder main.o hash.o

main.o: main.cpp hash.h
	$(CC) $(CFLAGS) -c main.cpp

hash.o: hash.cpp hash.h
	$(CC) $(CFLAGS) -c hash.cpp

clean:
	rm -f encoder *.o
