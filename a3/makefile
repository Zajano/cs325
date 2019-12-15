OBJS	= shopping.o
SOURCE	= shopping.cpp
OUT	= shopping
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

shopping.o: shopping.cpp
	$(CC) $(FLAGS) shopping.cpp

clean:
	rm -f shopping $(OBJS) $(OUT)
