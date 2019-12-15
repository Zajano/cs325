OBJS	= stoogetime.o
SOURCE	= stoogetime.cpp
OUT	= stoogetime
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

stoogetime.o: stoogetime.cpp
	$(CC) $(FLAGS) stoogetime.cpp

clean:
	rm -f stoogetime $(OBJS) $(OUT)
