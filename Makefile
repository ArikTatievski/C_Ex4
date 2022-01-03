CC=gcc
AR=ar
FLAGS= -Wall -g

all: graph

graph: main.o Node.o Edge.o graphAlgo.o PriorityQueue.o
	$(CC) $(FLAGS) -o graph main.o Node.o Edge.o graphAlgo.o PriorityQueue.o
main.o: main.c Graph.h graphAlgo.h
	$(CC) $(FLAGS) -c main.c
graphAlgo.o: graphAlgo.c graphAlgo.h PriorityQueue.h
	$(CC) $(FLAGS) -c graphAlgo.c
Node.o: Node.c Graph.h
	$(CC) $(FLAGS) -c Node.c
Edge.o: Edge.c Graph.h
	$(CC) $(FLAGS) -c Edge.c
PriorityQueue.o: PriorityQueue.c PriorityQueue.h
	$(CC) $(FLAGS) -c PriorityQueue.c
.PHONY: clean all
clean:
	rm -f *.o *.a *.so graph