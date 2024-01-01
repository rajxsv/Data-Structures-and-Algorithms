/*#include <iostream>
#include <climits>
using namespace std;

const int N = 0;

bool ratInMaze(int n , int m ,char arr[][1000],int soln[][100],int i , int j){

	if(i == n && j== m && arr[n][m]=='O'){

		soln[n][m]=1;
		for (int x = 0; x <= n; ++x){
			for(int y =0;y<=m;y++){
				cout <<soln[x][y]<<" ";
			}

			cout << endl;
		}
		return true;
	}

	if(arr[i][j]=='X'){
		return false;
	}
	if(i>n || j>m){
		return false;
	}
	soln[i][j]=1;
	
	bool right = false;
	bool down = false;

	right = ratInMaze(n,m,arr,soln,i,j+1);

	if(!right){
		down = ratInMaze(n,m,arr,soln,i+1,j);
	}
	// if it have a solution at any point then it will print the soln 
	// so when we return to find other soln we need to mark the values 
	// at that stack as back to zero to print and keep other solutions
 	// independent and also print them'
 	
 	soln[i][j] = 0;

 	return right | down; 
}

int main(){
	int n, m;
    cin >> n >> m;

    char arr[1000][1000];

	for (int x = 0; x < n; ++x){
			for(int y =0;y<m;y++){
				cin>>arr[x][y];
			}
		}

	int soln[100][100]={0};

	bool ans=ratInMaze(n-1,m-1,arr,soln,0,0);

	if(!ans){
		cout<<"-1"<<endl;
	}

	return 0;
}*/

// Above code doesnt work idk why (the compiler from which it is erased)
#include <iostream>
using namespace std;

bool solveRatInMaze(char v[1000][1000], int ans[1000][1000], int i, int j, int n, int m) {
    if ((i == n - 1) && (j == m - 1) && (v[i][j] == 'O')) {
        ans[i][j] = 1;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                cout << ans[x][y] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if (i == n || j == m) {
        return false;
    }
    if (v[i][j] == 'X') {
        return false;
    }
    ans[i][j] = 1;
    bool right = solveRatInMaze(v, ans, i, j + 1, n, m);
    if (right) {
        return true;
    }
    bool down = solveRatInMaze(v, ans, i + 1, j, n, m);
    if (down) {
        return true;
    }
    ans[i][j] = 0;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    char v[1000][1000];
    // vector<vector<char>> v(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    // vector<vector<bool>> ans(n, vector<bool> (m, 0));
    int ans[1000][1000] = {0};
    if (!solveRatInMaze(v, ans, 0, 0, n, m)) {
        cout << -1 << endl;
    }
    return 0;
}

















// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
