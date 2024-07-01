#include<bits/stdc++.h>
using namespace std;

class DS {
public:

    vector<int> size;
    vector<int> parent;

    DS(int n) {
        size.resize(n+1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++) {
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

int main() {
    int pods = 3;
    int n = 2;

    vector<vector<int>> conn = {{1,2},{2,3}};
    vector<vector<int>> q = {{2,2},{1,2},{2,1},{2,3},{1,1}};
 
    // int pods = 4;
    // int n = 4;
    
    // vector<vector<int>> conn = {{1,2},{2,3},{1,4},{4,3}};
    // vector<vector<int>> q = {{2,3},{1,3},{2,1},{1,1}};

    // int pods = 2;
    // int n = 1;

    // vector<vector<int>> conn = {{1,2}};
    // vector<vector<int>> q = {{1,2}};

    DS* d = new DS(pods+1);

    for(int i=0; i<n; i++) {
        d->unionbySize(conn[i][0],conn[i][1]);
    }

    unordered_map<int,set<int>> um;
    vector<int> par = d->parent;

    for(int i=1; i<=pods; i++) {
        um[par[i]].insert(i);
    }

    for(int i=0; i<q.size(); i++) {
        int type = q[i][0];
        int pod = q[i][1];
        int curPar = par[pod];
        int res = -1;

        if(type==1) {
            if(um[curPar].find(pod) != um[curPar].end()) {
                res = pod;
            } else if(um[curPar].size()>0) {   
                res = *(um[curPar].begin());
            }
            cout << res << endl;
        } else {
            if(um[curPar].find(pod)!= um[curPar].end()) {
                um[curPar].erase(pod);
            }
        }
    }

    return 0;
}