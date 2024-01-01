#include <iostream>
#include <vector>
using namespace std;
//Bottom up and top down should be thought of as in a 'recursive stack manner'


//every recursion programme can be easily transformed into dp approach
//the aim is to store the repeating call stacks in recurson and then use them later in other calls


// the following are the require conditions for recursion -> dp
//optimal substructure
//overlapping subproblems
int fib(int n , vector<int> &dp){
	if(n<=1){
		return dp[n]=n;
	}

	if(dp[n]!=0){
		return dp[n];
	}

	int ans = fib(n-1,dp) + fib(n-2,dp);

	return dp[n]=ans;
}

int fibUP(int n){
	vector<int> dp(100);
	dp[1]=1;

	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main(){

	int n;
	cin>>n;
	vector<int> dp(100);
	cout<<fib(n,dp)<<endl;
	cout<<fibUP(n);

	return 0;
}