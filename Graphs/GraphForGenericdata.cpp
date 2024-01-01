//Make a graph fool 
#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <queue>
using namespace std;

//distance calculated bu level order is shortest
//for unweighted graph


//lets build a generic graph
template<typename T> 
class Graph{
	map<T,list<T>> l;
	//adj list
public:	
	void addEdge(T x,T y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void BFS(T src){
		map<T,bool> visited;
		queue<T> q;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			T node = q.front();
			q.pop();

			cout<<node<<" ";
			for(auto nbr : l[node]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr]=true;
				}
			}
		}

		return;
	}

	void dfsHelper(T src,map<T,bool> &visited){
		//rec func that will traverse the graph
		
		//when we enter we just print that one
		cout<<src<<" ";
		visited[src]=true;
		//go to any nbr of this 
		for(auto nbr:l[src]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);
			}
		}
	}

	void DFS(T src){
		//the main role of this func is just create the map
		map<T,bool> visited;

		for(auto p:l){
			T node = p.first;
			visited[node]=false;
		}

		//point to note if this was a bidirectional graph 
		// it wont matter whether we use a for loop here ot not but 
		// if it is directional then surelt it makes a difference 
		// as there is a chance we might miss nodes for eg in the problem of topological sort
	w
		for(auto p:l){
			if(!v[p.first]){
				dfsHelper(p.first,visited);
			}
		}


		cout<<endl;
	}

	void singleSourceShortestPath(T src){
		map<T,int> dist;
		queue<T> q;

		for(auto node_pair:l){
			T node = node_pair.first;
			dist[node]=INT_MAX;
		}

		q.push(src);
		dist[src]=0;

		while(!q.empty()){
			T node = q.front();
			q.pop();

			// cout<<node<<" ";
			for(auto nbr : l[node]){
				if(dist[nbr]==INT_MAX){ 
					q.push(nbr);
					dist[nbr] = dist[node]+1; //just like distance from parent which in place could have a grandparent
				}
			}
		}
		//print all the dist to every node
		for(auto node_pair : l){
			T node = node_pair.first;
			int d = dist[node];
			cout<<"Node "<< node << " dist from src "<< d << endl;
		}
	}

};



int main(){

	Graph<int> g;

	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);

	g.BFS(0);
	g.DFS(0);

	g.singleSourceShortestPath(0);


}