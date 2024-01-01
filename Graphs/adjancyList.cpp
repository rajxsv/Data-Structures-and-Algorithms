#include <iostream>
#include <list>
using namespace std;

/*
	
	adjancy list relates elements in the following manner

	0 -> 1,2
	1 -> 2,0
	2 -> 3,0,1
	3 -> 2

*/

class Graph {
	int V;
	list<int>* l; //list of pointer to lists which will be made on demand
public:
	Graph(int V){
		this->V=V;
		l = new list<int>[V]; //pinter to a list with no. of vertices given
	}

	void addEdge(int x,int y){
		l[x].push_back(y);    
		//if 0 -> 1 then surely
		// 1 -> 0
		l[y].push_back(x);
	}

	void printAdjancyList(){
		//iterate over all vertices
		for(int i=0;i<V;i++){
			cout<<"Vertex "<<i<<" -> ";
			for(auto nbr : l[i]){
				cout<<nbr<<" ";
			}
			cout<<endl;
		}
	}
};

int main(){

	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(1,2);

	g.printAdjancyList();

	return 0;
}