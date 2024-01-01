#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

template<typename T>
class Graph{
	unordered_map<T,list<pair<T,int>>> m;
public:
	void addEdge(T u,T v,int dist,bool bidir=true){
		m[u].push_back({v,dist});
		if(bidir){
			m[v].push_back({u,dist});
		}
	}
	void printAdjList(){
		for(auto j:m){
			cout<<j.first<<"->";
			for(auto l:j.second){
				cout<<"("<<l.first<<","<<l.second<<") ";
			}
			cout<<endl;
		}
	}
	void dijkstraSSSP(T src){
		unordered_map<T,int> dist;

		for(auto j:m){
			dist[j.first]=INT_MAX;
		}

		set<pair<int,T>> s; //sorting acc to first so we ke[t it as distance
		dist[src]=0;
			
		s.insert({dist[src],src});

		while(!s.empty()){
			//find pair at front
			auto p = *s.begin();

			T node = p.second;
			int nodeDist = p.first;

			s.erase(s.begin());

			//iterate neighbours of cur node
			for(auto nbr:m[node]){
				
			}

		}
	}
};



int main(){

	Graph<string> g;

	g.addEdge("Amritsar","Delhi",1);
	g.addEdge("Amritsar","Jaipur",4);
	g.addEdge("Jaipur","Delhi",2);
	g.addEdge("Jaipur","Mumbai",8);
	g.addEdge("Bhopal","Agra",2);
	g.addEdge("Mumbai","Bhopal",3);
	g.addEdge("Agra","Delhi",1);

	g.printAdjList();

	return 0;
}
