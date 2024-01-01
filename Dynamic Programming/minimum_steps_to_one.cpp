#include <iostream>
#include <climits>
using namespace std;

// for a number n u have 3 options either to divide it by 3 (ifn%3==0) similarly 
//divide it by 2 (if(n%2==0)) or you can always n-1 we have to find the min no. of steps to reach 1

int fun(int n,int dp[]){
	if(n<=1)return 0;

	int a,b,c;

	a=b=c=INT_MAX;
	if(dp[n]!=0){
		return dp[n];
	}
	if(n%3==0){
		a=fun(n/3,dp);
	}
	if(n%2==0){
		b=fun(n/2,dp);
	}
	c=fun(n-1,dp);

	int ans = min(a,min(b,c))+1;
	return dp[n] = ans;

}

int main(){

	int n;
	cin>>n;
	int dp[100000] = {0};

	cout<<fun(n,dp);
	return 0;
}