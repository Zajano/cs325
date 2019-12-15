OBJS	= mergeTime.o
SOURCE	= mergeTime.cpp
OUT	= mergeTime
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

mergeTime.o: mergeTime.cpp
	$(CC) $(FLAGS) mergeTime.cpp

clean:
	rm -f mergeTime $(OBJS) $(OUT)
