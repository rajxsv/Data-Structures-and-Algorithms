#include <iostream>
#include<cstring> 
#include<climits> 
using namespace std;

int main() {
	int N,K,X;
	cin>>N>>K>>X;
	int grid[N][2];
	for(int i=0;i<N;i++){
	    for(int j=0;j<2;j++){
	        cin>>grid[i][j];
	    }
	}
	int k = grid[N-1][1];
	int arr[k+1];
	memset(arr, 0, sizeof(arr));
	for(int i=0;i<N;i++){
	    int m=grid[i][0];
	    int n=grid[i][1];
	    for(int z=m;z<=n;z++){
	        arr[z]++;
	    }
	}
	int S;
	
	
	int ans=INT_MIN;
	
	for(int i=0;i<=X;i++){
	    int sum=0;
	    for(int j=i;j<=k;j+=K){
	        sum+=arr[j];
	    }
	    if(sum>ans){
	        ans=sum;
	        S=i;
	    }
	    
	 }
	cout<<S<<" "<<ans;
	return 0;
}