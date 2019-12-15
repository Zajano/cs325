OBJS	= mergesort.o
SOURCE	= mergesort.cpp
OUT	= mergesort
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

mergesort.o: mergesort.cpp
	$(CC) $(FLAGS) mergesort.cpp

clean:
	rm -f mergesort $(OBJS) $(OUT)
