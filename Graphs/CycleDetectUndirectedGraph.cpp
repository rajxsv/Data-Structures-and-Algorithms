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
		l[y].push_back(x);
	}

	bool cycleHelper(int node,bool *visited,int parent){
		visited[node]=true;
		for(auto nbr:l[node]){
			if(!visited[nbr]){
				//rec visit nbr
				if(cycleHelper(nbr,visited,node)){
					return true;
				}
			}else if(nbr!=parent){
				return true;
			}
		}
		return false;
	}

	isTree1(){
		//using dfs
		bool *visited=new bool[V];
		for(int i=0;i<V;i++){
			visited[i]=false;
		}
		return cycleHelper(0,visited,-1);
	}

	bool isTree(int src){
		//The concept it if we can reach a node tha can be reached through multiple paths then no its not a tree
		// dont consider the parent node 1<->2<->3  dont check 1 while checking for 2 if we  check from left side
		//BFS WAY
		bool *visited = new bool[V];
		int *parent = new int[V];

		queue<int> q;

		for(int i=0;i<V;i++){
			visited[i]=false;
			parent[i]=i;
		} 
		
		q.push(src);
		visited[src]=true;

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(auto nbr:l[node]){
				if(visited[nbr]==true && parent[node]!=nbr){
					//cycle is present
					return false;
				}else if(!visited[nbr]){
					q.push(nbr);

					visited[nbr]=true;
					parent[nbr]=node;
				}
			}
		}
		return true;

	}
};

int main(){

	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);

	if(g.isTree1()){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}