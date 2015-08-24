all: submission

submission: shortestPath.o
	g++ -g shortestPath.o -o submission
	
shortestPath.o: shortestPath.cpp
	g++ -g -c shortestPath.cpp
	
clean:
	rm -f *.o submission
