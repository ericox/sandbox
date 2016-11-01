all: graph dijkstra.o

graph: graph.o
	g++ -std=c++11 -o graph graph.o

graph.o: graph.cpp
	g++ -std=c++11 -c graph.cpp

dijkstra.o: dijkstra.cpp
	g++ -std=c++11 -c dijkstra.cpp
