#include <bits/stdc++.h>
using namespace std;

#define f(i,s,e) for(int i=s;i<e;i++)

void solve() {
    int n = 3;
    int m = 5;
    
    vector<int> arr = {2,4,1,8,9};
    // vector<int> arr = {2,2,2,3};
    // vector<int> burst = {1,3,1,2};
    vector<int> burst = {7,9,2,4,5};
    // vector<int> arr = {0,1,2,4};


    vector<int> res(m);
    set<vector<int>> set;
    vector<vector<int>> nums;
    stack<vector<int>> aux;

    for(int i=0; i<m; i++) nums.push_back({(int)arr[i],(int)(arr[i] + burst[i]),(int)i});
    
    sort(nums.begin(), nums.end(), 
    [&](vector<int> &a, vector<int> &b){
        if(a[0] != b[0]) return a[0] < b[0]  ;
        return a[2] < b[2];
    });
    
    for(int i=0; i<n; i++) set.insert({i,-1});

    for(int i=0; i<m; i++) {
        aux = {};
        auto it = set.begin();
        int ans = -1;
        while(it != set.end() && ((*it)[1]) != -1 && nums[i][0] < ((*it)[1]))it++;   
        
        if(it != set.end()) {
            int ind = (*it)[0];

            ans = ind + 1;
            set.insert({ind,nums[i][1]});
            set.erase(it);
        }
        res[i] = ans;
    }
    
    for(int i=0; i<m; i++) cout << res[i] << " ";
}

int main()
{
    solve();
    return 0;

}