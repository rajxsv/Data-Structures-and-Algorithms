#include <iostream>
#include <cstring>
using namespace std;
bool solve(int board[10][10],int n,int* x,int* y,int i,int j,int cnt){
	// at 64 the programme is printing
	if(cnt==(n*n)){
		for(int k=0;k<n;k++){
			for(int w=0;w<n;w++){
				cout<<board[k][w]<<"  ";
			}
			cout<<endl;
		}
		return true;
	}
	// rec case
	board[i][j] = cnt;
	for(int k=0;k<8;k++){
		// assume it fine
		int nextx=i+x[k];
		int nexty=j+y[k];
		if(nextx<n && nexty<n && nextx>=0 && nexty>=0 && board[nextx][nexty]==(0)){
			if(solve(board,n,x,y,nextx,nexty,cnt+1)){
				return true;
			}
			board[nextx][nexty]=0;
		}
	}
	board[i][j] = 0;
	return false;
}
int main(){
	int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	int n;
	cin >> n;

	int board[10][10];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			board[i][j]=0;
		}
	}


	int cnt=1;
	// board[0][0]=0;

	solve(board,n,x,y,0,0,cnt);

	return 0;
}