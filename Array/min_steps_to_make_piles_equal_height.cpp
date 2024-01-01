#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

void solve(vector<int> &v){
    priority_queue<pair<int,int>> pq;
    unordered_map<int,int> freq;

    for(auto i:v){
        freq[i]++;   // O(n)
    }
    // O(n + un*log(un) + O(un)*(log(un)+log(un)+log(un)))
    // O(n + (log(un)(ub + 3*un)));
    // O(n + 4*un*log(un));
    // O(n + nlog(n))  // worst case scneario un == n
    // O(n(1+log(n)))

    // O(nlog(n)) - TC 
    // O(2*n)     - SC


    for(auto p:freq){
        pq.push({ p.first,p.second }); // O(uniqueElements*log(uniqueElements))
    }

    int ans = 0;

    while(pq.size() > 1){   // O(uniqueElements)
        int n = pq.top().first; // O(log(uniqueElements))
        int times = pq.top().second;
        pq.pop();

        ans+= times;


        auto p = pq.top();     // O(log(uniqueElements))
        pq.pop();

        p.second += times;   
        pq.push(p);             // O(log(uniqueElements))
    
    }

    cout << ans << endl;
}

int main(){

    vector<int> v = {1,1,2,2,2,3,3,3,4,4};
    // vector<int> v = {5,2,1};
    solve(v);
    return 0;
}