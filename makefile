CC = g++
CFLAGS =
#CFLAGS = -lm -O2 -Wall

all: charsplitter.o bin/charsplitter

charsplitter.o : lmtoolkit/main.cpp
	$(CC) $(CFLAGS) $(OPT_DEF) -c lmtoolkit/main.cpp

bin/charsplitter:
	$(CC) -o bin/charsplitter main.o

clean:
	rm -rf *.o charsplitter

