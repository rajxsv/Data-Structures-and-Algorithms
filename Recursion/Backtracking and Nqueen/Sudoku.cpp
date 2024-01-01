#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int N = 0;
bool can_place(int mat[9][9],int i,int j,int n,int no){

	//ro co check
	for(int k=0;k<n;k++){
		if(mat[k][j]==no || mat[i][k]==no){
			return false;
		}
	}

	int rn=sqrt(n);
	int sx=(i/rn)*rn;
	int sy=(j/rn)*rn;

	for(int x=sx;x<sx+rn;x++){
		for(int y=sy;y<sy+rn;y++){
			if(mat[x][y]==no){
				return false;
			}
		}
	}
	return true;
}

bool sudoku(int mat[9][9],int n,int i,int j){
	// only one condition required
	// as the j==n would never exist
	if(i==n){
		// printthe array
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout<<mat[x][y]<<" ";
			}
			cout<<endl; 
		}
		return true;
	}
	if(j==n){
		return sudoku(mat,n,i+1,0);
	}
	if(mat[i][j]!=0){
		return sudoku(mat,n,i,j+1);
	}
	
	// if(i>=n || j>=n){
	// 	return false;
	// }
	// place the numbers


	for(int no=1;no<=n;no++){
		if(can_place(mat,i,j,n,no)){
			mat[i][j]=no;
			if(sudoku(mat,n,i,j+1)){
				return true;
			}
		}
	}	
	
	mat[i][j]=0;
	return false;
}

int main(){
	int n;
	cin >> n;
	int mat[9][9];
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j){
			cin >> mat[i][j];	
		}
	}

	if(!sudoku(mat,n,0,0)){
		cout << "No";
	}


	
	return 0;
}