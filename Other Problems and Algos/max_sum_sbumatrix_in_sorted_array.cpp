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

   
    //suffix sum matrix is ready

    int result = INT_MIN;

    for(int i = r- 1 ; i >= 0 ; i--)
    {
        for(int j = c-1 ; j >= 0 ; j--)
        {
            result = max(arr[i][j],result);
        }
    }

    cout << result ;
    
    return 0;
}