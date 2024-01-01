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

	int singleSourceShortestPath(T src,T dest){
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
				if(dist[nbr]==INT_MAX){   //this dist[nbr] value not being equal to INT_MAX makes sure a visited node is not changed
					q.push(nbr);
					dist[nbr] = dist[node]+1; //just like distance from parent which in place could have a grandparent
				}
			}
		}
		//print all the dist to dest node
		
		for(auto i:dist){
			cout<<i.first<< " "<<i.second<<endl;
		}
		cout<<dist[36]<<endl;
		return dist[dest];
	}

};

int main(){

	int board[50]={0};

	board[0]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]= -13;
	board[20]= -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	// add all edges to graph
	Graph<int>g;

	for(int i=0;i<=36;i++){
		for(int dice=1;dice<=6;dice++){
			int reach = i+dice;
			reach+=board[reach];

			if(reach<=36){
				g.addEdge(i,reach);  //unweighted directed edge
			}
		}
	}
	g.addEdge(36,36);

	g.singleSourceShortestPath(0,36);

	return 0;
}