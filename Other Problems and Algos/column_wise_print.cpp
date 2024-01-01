#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int row = 0;
    int col = 0;

    for (col = 0; col < m; col++)
    {
        if(col%2==0)
        {
            for(row = 0 ; row < n ; row++)
            {
                cout << arr[row][col]<<", ";
            }
        }
        else
        {
             for(row = n-1 ; row >= 0 ; row--)
            {
                cout << arr[row][col]<<", ";
            }
        }
    }
    cout << "END";

        return 0;
}