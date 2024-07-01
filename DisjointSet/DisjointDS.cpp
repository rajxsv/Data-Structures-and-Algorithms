#include<iostream>
#include<vector>
using namespace std;

class DS{
private:
    vector<int> size;
    vector<int> parent;
public:
    DS(int n){
        size.resize(n+1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionbySize(int u, int v){
        int ultimateParent_u = findPar(u);
        int ultimateParent_v = findPar(v);

        if(size[ultimateParent_u] > size[ultimateParent_v]){
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u]+=size[ultimateParent_v];
        }else{
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v]+=size[ultimateParent_u];
        }
    }

};

int main(){

    DS* ds1 = new DS(5);

    ds1->unionbySize(1,2);
    ds1->unionbySize(2,3);
    ds1->unionbySize(4,5);
    
    if(ds1->findPar(3) == ds1->findPar(5)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }

    ds1->unionbySize(3,4);

    if(ds1->findPar(3) == ds1->findPar(5)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }

    return 0;
}


// *********** ************** //

/*
    #include<iostream>
#include<vector>
using namespace std;
class Disjointset{
    vector<int>rank,parent,size;
    public:
    Disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i =0 ; i<=n ; i++){
            parent[i]=i;
            size[i] =1; 
        }
    }

    int find_up(int node){
        if(node == parent[node])return node;
        return parent[node] = find_up(parent[node]);
    }

    //combining two nodes
    void unionByRank(int u , int v){
        int ulp_u = find_up(u) , ulp_v = find_up(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = find_up(u);
        int ulp_v = find_up(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; 
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
int main()
{
    Disjointset ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    //if 3 & 7 belong to the same or not
    if(ds.find_up(3) == ds.find_up(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    ds.unionByRank(3,7);
    //if 3 & 7 belong to the same or not
    if(ds.find_up(3) == ds.find_up(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }

    return 0;
}

int detectCycle(int V, vector<int>adj[])
	{
	    Disjointset ds(V);
	    for(int i = 0 ; i < V ; i++){
	        
	        for(int it : adj[i]){
	            
	            int u = i;
	            int v = it;
	            
	            if(u<v && ds.find_up(u) == ds.find_up(v)){
	                return 1;
	            }
	            else{
	                ds.unionBySize(u,v);
	            }
	        }
	    }
	    return 0;
	}
*/