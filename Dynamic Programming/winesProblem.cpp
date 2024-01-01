#include <iostream>
#include <vector>

using namespace std;
// we have an array of wine bottel prices 
// each bottel price is calculated by the ith year as priceOfBottel*i
// in any year you can sell one of the extremes
// what is the max possible profit?

int profit(int wines[],int i,int j,int y,int dp[][100]){
	if(i>j)return 0;
	if(dp[i][j]!=0)return dp[i][j];
	int op1 = wines[i]*y + profit(wines,i+1,j,y+1,dp);
	int op2 = wines[j]*y + profit(wines,i,j-1,y+1,dp);

	return dp[i][j]=max(op1,op2);
}
int main(){

	int arr[] = {2,3,5,1,4};
	int n = sizeof(arr)/sizeof(int);
	int dp[100][100] = {0};
	cout<<profit(arr,0,n-1,1,dp);
	return 0;
}