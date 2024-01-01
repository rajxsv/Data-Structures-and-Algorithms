#include <iostream>
#include <cstring>
using namespace std;
// int
 bool NQueen(int arr[100][100] , int n , int i){
	// base rec
	if(i==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	// int cnt = 0;
	for(int j=0;j<n;j++){
		if(can_place(arr,i,j,n)){
			arr[i][j]=1;
			// cnt+=NQueen(arr,n,i+1);
			NQueen(arr,n,i+1);
			arr[i][j]=0;
		}
	}
	// return cnt;
	return false;
}	
int main(){

	int n;
	cin >> n;

	int arr[100][100];
	memset(arr,0,sizeof(arr));

	int col[n],ld[n],rd[n];
	NQueen(arr,n,0);

	return 0;
}