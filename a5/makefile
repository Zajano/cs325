OBJS	= wrestler.o
SOURCE	= wrestler.cpp
OUT	= wrestler
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

wrestler.o: wrestler.cpp
	$(CC) $(FLAGS) wrestler.cpp

clean:
	rm -f wrestler $(OBJS) $(OUT)
