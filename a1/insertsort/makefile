OBJS	= insertsort.o
SOURCE	= insertsort.cpp
OUT	= insertsort
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

insertsort.o: insertsort.cpp
	$(CC) $(FLAGS) insertsort.cpp

clean:
	rm -f insertsort $(OBJS) $(OUT)
