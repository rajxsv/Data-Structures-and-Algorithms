#include<iostream>
#include <priority_queue>
using namespace std;

int ropes(int arr[]){
    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+n);

    int ans = 0;
    int tot = 0;

    while(pq.size()>1){
        ans = 0;

        ans += pq.top();
        pq.pop();
        ans += pq.top();
        pq.pop();

        tot += ans;
        pq.push(ans);
    }

    return tot;
}

int main(){
    int n;
    cin >> n;

    int ropes[n];

    solve(ropes);

    return 0;
}