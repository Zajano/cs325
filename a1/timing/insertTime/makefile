OBJS	= insertTime.o
SOURCE	= insertTime.cpp
OUT	= insertTime
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

insertTime.o: insertTime.cpp
	$(CC) $(FLAGS) insertTime.cpp

clean:
	rm -f insertTime $(OBJS) $(OUT)
