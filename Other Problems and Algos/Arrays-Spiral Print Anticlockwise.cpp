#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;

    int arr[m][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int sr = 0, sc = 0, er = m - 1, ec = n - 1;

    while(sr<=er && sc<=ec){
        //first row
        for(int i=sc;i<=ec;i++){
            v.push_back(matrix[sr][i]);
        }
        sr++;
        
        // left most col 
        for(int i=sr;i<=er;i++){
            v.push_back(matrix[i][ec]);
        }
        
        ec--;
        
        //last row
        if(sr<=er){
            for(int i=ec;i>=sc;i--){
                v.push_back(matrix[er][i]);
            }
            er--;
        }
        //right most col
        if(sc<=ec){
            for(int i=er;i>=sr;i--){
                v.push_back(matrix[i][sc]);
            }
            sc++;
        }
        
    }

    return 0;
}