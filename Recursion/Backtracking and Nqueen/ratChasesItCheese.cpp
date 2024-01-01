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
    if (i == n || j == m || i<0 || j<0) {
        return false;
    }
    if (v[i][j] == 'X' || ans[i][j] == 1) {
        return false;
    }
    ans[i][j] = 1;
    
    // Notice these return statements used for nor reading the code ahead\
    // if we get the desired result
    // and return statement executes

    bool right = solveRatInMaze(v, ans, i, j + 1, n, m);
    if (right) {
        return true;
    }
    bool down = solveRatInMaze(v, ans, i + 1, j, n, m);
    if (down) {
        return true;
    }

    bool up = solveRatInMaze(v,ans,i-1,j,n,m);
    if(up){
        return true;
    }
    
    bool left = solveRatInMaze(v,ans,i,j-1,n,m);
    if(left){
        return true;
    }

    // backtracking 
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
        cout << "NO PATH FOUND" << endl;
    }
    return 0;
}