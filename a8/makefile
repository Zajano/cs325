OBJS	= binpack.o
SOURCE	= binpack.cpp
OUT	= binpack
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

binpack.o: binpack.cpp
	$(CC) $(FLAGS) binpack.cpp

clean:
	rm -f binpack $(OBJS) $(OUT)
