/*

A cycle in a graph is a path that starts and ends at the same vertex, 
and includes at least one edge. In other words, it's a sequence of vertices 
that you can follow by following the edges of the graph, starting and ending 
at the same vertex, and passing through at least one other vertex more than once.

In an undirected graph, a cycle can be detected by performing 
a depth-first search (DFS) of the graph. During the search, 
if you encounter a vertex that has already been visited, 
and that vertex is not the parent of the current vertex, 
then you have found a cycle. This is because in an undirected graph, 
there can be no cycles that include the parent of the current vertex, 
because that would imply that you had already visited that vertex earlier in the search.

In a directed graph, cycles can be a bit trickier to detect. 
One common approach is to use a modified DFS algorithm called Tarjan's algorithm.
Tarjan's algorithm uses a technique called "backtracking" 
to identify cycles in a directed graph. Specifically, during the DFS, 
if you encounter a vertex that is already on the DFS stack, 
then you have found a cycle. This is because the DFS stack contains 
the path from the start vertex to the current vertex, and if you encounter 
a vertex that is already on the stack, then you have found a path that goes 
from the current vertex back to itself, which is a cycle.

in undirected graph is done in isTree.cpp
here we have directed graph

*/


/*

*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
	int V;
	list<int>* l;
public:
	Graph(int V){
		this->V=V;
		l = new list<int>[V]; 
	}

	void addEdge(int x,int y){
		l[x].push_back(y);
	}

	bool cycleHelper(int node,bool *visited,bool *stack){
		visited[node]=true;
		///and also becomes a part of stack(current path)
		stack[node]=true;

		for(int nbr:l[node]){
			if(stack[nbr]){
				return true;
			}else if(!visited[nbr]){
				if(cycleHelper(nbr,visited,stack)){
					return true;
				}
			}
		}

		//while leaving the stack
		stack[node]=false;
		return false;
	}

	bool containesCycle(int src){
		// our goal is to find a back node	

		bool *visited= new bool[V];
		bool *stack= new bool[V];

		for(int i=0;i<V;i++){
			visited[i]=stack[i]=false;
		}

		return cycleHelper(src,stack,visited);

	}
};

int main(){

	Graph g(4);

	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(1,5);
	g.addEdge(5,6);
	g.addEdge(4,2);

	g.containesCycle(0)


	return 0;
}

