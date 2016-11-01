all: main main.o graph.o prim_mst.o

main: main.o graph.o prim_mst.o
	g++ --std=c++11 -o main main.o graph.o prim_mst.o
	
main.o: main.cpp
	g++ --std=c++11 -c main.cpp

prim_mst.o: prim_mst.cpp 
	g++ --std=c++11 -c prim_mst.cpp

graph.o: graph.cpp
	g++ --std=c++11 -c graph.cpp

clean:
	rm *.o main
