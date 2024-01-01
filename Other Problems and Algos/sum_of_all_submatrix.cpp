#include <bits/stdc++.h>
using namespace std;

void approach3(int **arr, int r, int c)
{
    int sum = 0;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){ 
        // possible top lefts
            int tl = (i + 1) * (j + 1);

            // possible bottom rights
            int br = (r - i) * (c - j);

            sum += arr[i][j] * (tl * br);
        }
    }

    cout << "Using approach 3 sum is " << sum << "\n\n";
}

void approach2(int **arr, int r, int c){
    int **arrp = new int *[r];

    for (int j = 0; j < r; j++){
        arrp[j] = new int[c];
    }

    // initialising first row and column just like 1d com_sum array
    // first element of prefix matrix

    int sum = 0;
    arrp[0][0] = arr[0][0];
    
    // initizialise first col
    for (int i = 1; i < c; i++){
        arrp[0][i] = arrp[0][i - 1] + arr[0][i];
        
    }
    // initizialise first row
    for (int i = 1; i < r; i++){
        arrp[i][0] = arrp[i - 1][0] + arr[i][0];
        
    }
    // making the finall step to create the 2d sum prefix matrix

    for (int i = 1; i < r; i++){
        for (int j = 1; j < c; j++){
            // adding the cuurent element the sum till i-1 , j and i,j-1 but gettting extra of i-1,j-1 so subtracting once
            arrp[i][j] = arrp[i - 1][j] + arrp[i][j - 1] - arrp[i - 1][j - 1] + arr[i][j];
            
        }
    }

    //to see whether the prefix sum array is read or not------------------
    for(int i = 0 ; i < r ; i ++){
        for(int j = 0 ; j < c ; j++){
            cout << arrp[i][j] << " ";
        }
        cout << endl;
    }

    // our 2d prefix matrix is now ready -----------------------------------

    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            for(int x = i; x < r ; x++ )
            {
                for(int y = j ; y < c ; y++ )
                {
                    sum += arrp[x][yn] - arrp[i-1][y] - arrp[x][j-1] + arrp[i-1][j-1];
                }
            }
        }
    }


    cout << "The sum using approach 2 = " << sum << endl;
}

void approach1(int **arr, int r, int c)
{

    int sum = 0;

    for (int tl1 = 0; tl1 < c; tl1++)
    {
        for (int tl2 = 0; tl2 < r; tl2++)
        {
            for (int br1 = tl1; br1 < c; br1++)
            {
                for (int br2 = tl2; br2 < r; br2++)
                {
                    for (int x = tl1; x <= br1; x++)
                    {
                        for (int y = tl2; y <= br2; y++)
                        {
                            sum += arr[x][y];
                        }
                    }
                }
            }
        }
    }

    cout << "Using approach 1 sum is " << sum << "\n\n";
}

int main()
{
    int r, c;
    cin >> r >> c;
    // declaring a dynamically alloted 2d array

    int **aptr = new int *[r];

    for (int i = 0; i < c; i++)
    {
        aptr[i] = new int[c];
    }

    // inititalising it

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> aptr[i][j];
        }
    }

    approach1(aptr, r, c);
    approach2(aptr, r, c);
    approach3(aptr, r, c);
    
    return 0;
}