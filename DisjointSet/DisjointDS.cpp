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