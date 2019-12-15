OBJS	= stoogesort.o
SOURCE	= stoogesort.cpp
OUT	= stoogesort
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

stoogesort.o: stoogesort.cpp
	$(CC) $(FLAGS) stoogesort.cpp

clean:
	rm -f stoogesort $(OBJS) $(OUT)
