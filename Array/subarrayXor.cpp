#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


void solve(vector<int> &v,int target,int n){
    unordered_map<int,int> um;
    
    int ans = 0;
    
    int preXor = 0;
    um[preXor] = 1;

    for(int i=0;i<n;i++){
        preXor^=v[i];
        if(um.find(preXor^target) != um.end()){
            ans+=um[preXor^target];
        }
        um[preXor]++;
    }

    cout<<ans<<endl;
}

int main(){

    int d;
    cin>>d;

    vector<int> v;

    while(d!=-1){
        v.push_back(d);
        cin>>d;
    }

    int target;
    cin>>target;

    solve(v,target,v.size());

    return 0;
}