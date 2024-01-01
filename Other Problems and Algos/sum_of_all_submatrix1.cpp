#include<bits/stdc++.h>
using namespace std;

void approach1(int arr[][2])
{
    int sum = 0;

    for(int tl1 = 0 ; tl1 < 2 ; tl1++)
    {

        for(int tl2 = 0 ; tl2 < 2 ; tl2++)
        {

            for(int br1 = tl1 ; br1 < 2 ; br1++)
            {

                for(int br2 = tl2 ; br2 < 2 ; br2++)
                {

                    for(int x = tl1 ; x <= br1 ; x++)
                    {

                        for(int y = tl2 ; y<=br2 ; y++)
                        {
                                
                                sum+=arr[x][y];
                        }
                    }
                }
            }
        }    
    }

    
    cout << sum;
}

int main()
{
    int arr[2][2]={{1,1},{1,1}};
    
    approach1(arr);
    return 0;
}