OBJS	= scheduler.o
SOURCE	= scheduler.cpp
OUT	= scheduler
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

scheduler.o: scheduler.cpp
	$(CC) $(FLAGS) scheduler.cpp

clean:
	rm -f scheduler $(OBJS) $(OUT)
