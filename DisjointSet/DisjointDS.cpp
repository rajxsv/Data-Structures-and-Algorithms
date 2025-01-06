#include<bits/stdc++.h>
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
            parent[ultimateParent_v] = ultimateParent_u; // shote veeer da parent vadda veer
            size[ultimateParent_u]+=size[ultimateParent_v];  // parent veer da size increase krgya 
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

class DSU {
private:
    vector<int> parent, rank;
    int count;

public:
    DSU(int size) {
        parent.resize(size,-1);  // this is a nice trick, no land, no parent not even themselves
        rank.resize(size,0);
        count=0;
    }

    void addLand(int x) {
        if(parent[x]>=0) return;  // already land, do nothing
        parent[x]=x;
        count++;
    }
    
    bool isLand(int x) return parent[x]>=0;

    int numberOfIslands() return count;

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);  
    }

    void unionSize(int x, int y) {
        int parX = find(x);
        int parY = find(y);

        if(parX == parY) return;

        if(rank[parX]>rank[parY]) {
            parent[parY] = parX;
        } else if (rank[parY]>rank[parX]) {
            parent[parX] = parY;
        } else {
            parent[parX] = parY;
            rank[parX]++;
        }
        count--;
    }
};



class DSU {
private:
    vector<int> par, rank;

public:
    DSU(int size) {
        par.resize(size);
        rank.resize(size,0);
        for(int i=0; i<size; i++) par[i]=i;
    }

    int find(int x) {
        if(par[x]==x) return x;
        return find(par[x]);
    }

    void unionSize(int x, int y) {
        int parX = find(x);
        int parY = find(y);

        if(parX == parY) return;

        if(rank[parX] < rank[parY]) {
            par[parX] = parY;
        } else if(rank[parY] < rank[parX]) {
            par[parY] = parX;
        } else {
            par[parY] = parX;
            rank[parX]++;
        }
    }
};
