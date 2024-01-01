#include<iostream>
#include <cstring>
using namespace std;

int laddersOptimised(int n,int k){
    int dp[100]={0};

    dp[0] = dp[1] = 1;

    for(int i=2;i<=k;i++){
        dp[i]=2*dp[i-1];
        //dp[n-k] is 0
    }   

    for(int i=k+1;i<=n;i++){
        dp[i]=2*dp[i-1]-dp[i-k-1];
        //  dp[n] = dp[n-1] + (dp[n-1] - dp[n-k-1])
    }

    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }

    cout<<endl;

    return dp[n];

}

int laddersRec(int n, int k){
    // if(n == 0)return 1;

    // int ways = 0;

    // for(int i=1;i<=k;i++){
    //     if(n-i >= 0){
    //         ways += laddersRec(n-i,k);
    //     }
    // }
    // return ways;

    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    int ways = 0;   

    for(int i=1; i<=n; i++){
        ways = 0;
        for(int j=1;j<=k;j++){
            if(i-j >= 0){
                ways += dp[i-j];
            }
        }
        dp[i] = ways;
    } 
    return dp[n];
}



int main(){

    int n,k;

    cin>>n>>k;

    // cout<<laddersOptimised(n,k);
   
    cout<<laddersRec(n,k);


    return 0;
}