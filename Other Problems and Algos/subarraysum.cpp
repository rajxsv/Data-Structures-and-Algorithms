#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        int msum = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            cin >> arr[i];

        }

        int sum = INT_MIN;

        for(int i = 0 ; i < n ; i++)
        {

            if(arr[i]>0)
            {
                sum+=arr[i];

            }    
            else
            {
                sum = 0;
            }

            if(sum>msum)
                {
                    msum = sum;
                }

        }
    }

    return 0;
}