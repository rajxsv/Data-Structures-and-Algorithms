#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;

    int arr[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int sr = 0, sc = 0, er = m - 1, ec = n - 1;

    while (er >= sr)
    {
        if (ec > sc)
        {
            // first col
            for (int i = sr; i <= er; i++)
            {
                cout << arr[i][sc] << ", ";
            }
            sc++;
        }

        if (sr < er)
        {
            // last row
            for (int i = sc; i <= ec; i++)
            {
                cout << arr[er][i] << ", ";
            }
            er--;
        }
        // last col
        for (int i = er; i >= sr; i--)
        {
            cout << arr[i][ec] << ", ";
        }
        ec--;

        // first row
        for (int i = ec; i >= sc; i--)
        {
            cout << arr[sr][i] << ", ";
        }
        sr++;
    }
    cout << "END";
    return 0;
}