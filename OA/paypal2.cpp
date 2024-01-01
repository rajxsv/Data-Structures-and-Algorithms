#include<bits/stdc++.h>
using namespace std;

bool cmpi(vector<int> &a, vector<int> &b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[2] < b[2];
}

void solve() {

    // start here sanyam (arr and burst arrays dekhli aape ki naam aa) !! 

       int n = 3;
    int m = 5;
    
    vector<int> arrival = {2,4,1,8,9};
    vector<int> burst = {7,9,2,4,5};

    vector<int> comp(m);
    vector<int> res(m);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;

    for(int i=0; i<m; i++) {
        comp[i] = arrival[i] + burst[i];
    }

    vector<vector<int>> nums;
    for(int i=0; i<m; i++) {
        nums.push_back({arrival[i],comp[i],(int)i});
    }   

    sort(begin(nums), end(nums),cmpi);

    for(int i=0; i<n; i++) q.push({i,-1});

    for(int i=0; i<m; i++) {
        stack<vector<int>> aux;
        while(!q.empty() && q.top()[1] != -1 && (nums[i][0] < q.top()[1])) {
            aux.push(q.top());
            q.pop();
        }
        if(q.empty()) {
            res[i] = -1;
        }else{
            auto it = q.top();
            q.pop();
            res[i] = it[0] + 1;
            it[1] = nums[i][1];
            q.push(it);
        }

        while(!aux.empty()) {
            q.push(aux.top());
            aux.pop();
        }

    }
        for(auto i : res) cout << i << " " ;
}

int main()
{
        solve();
    return 0;

}