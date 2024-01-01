#include <iostream>
#include <cstring>
using namespace std;

bool can_place(int arr[100][100],int i,int j,int n){
	// col check
	for(int k=0;k<i;k++){
		if(arr[k][j]){
			return false;
		}
	}

	// upper left diag
	int row=i-1,col=j-1;
	while(row>=0 && col>=0){
		if(arr[row--][col--]){
			return false;
		}
	}
	// upper right diag
	row=i-1,col=j+1;
	while(row>=0 && col<n){
		if(arr[row--][col++]){
			return false;
		}
	}
	
	return true;
}
// int
 void NQueen(int arr[100][100] , int n , int i){
	// base rec
	if(i==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	for(int j=0;j<n;j++){
		if(can_place(arr,i,j,n)){
			arr[i][j]=1;
			NQueen(arr,n,i+1);
			arr[i][j]=0;
		}
	}
	return;
}	
int main(){

	int n;
	cin >> n;

	int arr[100][100];
	memset(arr,0,sizeof(arr));

	NQueen(arr,n,0);

	return 0;
}