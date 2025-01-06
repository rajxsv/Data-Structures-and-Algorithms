#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

int tc(int i,int j, vector<int> pd, vector<int> trees) {
    int tc = 0;
    for (int x = i;x<=i;++x) tc +=trees[x]* (pd[j]-pd[x]);
    // cout << tc << endl;
    return tc;
}

void preCompute(vector<int> &pd, vector<int> &distances, int n) {
    for (int i = 1; i < n; ++i) pd[i]=pd[i-1]+distances[i-1];
}

int solution(vector<int> trees, vector<int> distances, int k) {
    int n=trees.size();
    vector<int> pd(n+1,0);
    preCompute(pd, distances ,n);
    vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX));
    for (int i = 0; i < n; ++i) dp[i][0]=tc(0, i,pd,trees);
    for (int sm=1;  sm <= k; sm++) {
        for (int i=0;i < n;i++) {
            for (int j=0; j<i; j++) {
                int a=dp[i][sm];
                int b= dp[j][sm - 1]+tc(j + 1, i, pd, trees);
                dp[i][sm] =min(a,b);
            }
        }
    }
    // for (int i=0;i<=n;i++) {
    //     for(int j=0;j<=k;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout <<"/n";
    // }
    return dp[n - 1][k];
}

int main() {
    vector<int> trees = {1, 1, 2, 1};
    vector<int> distances = {20, 30, 10};
    int k = 1;
    
    cout << solution(trees, distances, k) << endl;
    return 0;
}