#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r , c ;
    cin >> r >> c;
    //we need a suffix sum matrix 
    int arr[r][c];
    
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            cin >> arr[i][j];
        }
       
    }


    //ROW WISE ADDITION
    for(int i = r-1 ; i>=0 ; i--)
    {
        for(int j = c-2 ; j >= 0 ; j--)
        {
            arr[i][j] += arr[i][j+1];
        }
    }

    for(int j = c-1 ; j >= 0 ; j--)
    {
        for(int i = r-2 ; i>= 0 ; i--)
        {
            arr[i][j]+=arr[i+1][j];
        }
    }

   

    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            cout << arr[i][j]<<" ";

        }
        cout << endl;
    }
    return 0;
}