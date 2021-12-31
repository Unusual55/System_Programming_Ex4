CC = gcc
AR = ar
FLAGS =-g -Wall

all: main lib_graph lib_algo

main: main.o lib_graph
	$(CC) $(FLAGS) main.o -o .main lib_graph.a

lib_graph: lib_graph.a

lib_graph.a: graph.o
	$(AR) -rcs lib_graph.a graph.o

graph.o: graph.c
	$(CC) $(FLAGS) -c graph.c

lib_algo: lib_algo.a

lib_algo.a: algo.o
	$(AR) -rcs lib_algo.a algo.o

algo.o: algo.c
	$(CC) $(FLAGS) 

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so main