#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector <int> coins = {1,7,10};

int min_change(int n,int* dp){
	if(n==0)return 0;

	if(dp[n]!=0){
		return dp[n];
	}
	int ans = INT_MAX;
	for(int i=0;i<coins.size();i++){
		if(n>=coins[i]){
			ans = min(ans,min_change(n-coins[i],dp) + 1);
		}
	}
	return dp[n] = ans;
}

int min_changeBottomUp(int n){
	int dp[100] = {0};

	for(int i=1;i<=n;i++){
		dp[i] = INT_MAX;
		for(int j=0;j<coins.size();j++){
			if(n>=coins[j]){
				int subprob = dp[n-coins[j]];
				dp[i] = min(dp[i],subprob+1);
			}
		}
	}
	return dp[n];
}

int main(){

	int n;
	cin>>n;

	int dp[1000] = {0};
	cout<<min_change(n,dp)<<endl;
	cout<<min_changeBottomUp(n);

	return 0;
}