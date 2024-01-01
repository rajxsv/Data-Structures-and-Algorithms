#include<bits/stdc++.h>
using namespace std;

bool verify(vector <int> &stalls , int n , int cows , int sep)
{
    //allocating the first cow
    int last_cow = stalls[0];
    int count = 1;

    for(int i = 1 ; i < n ; i++)
    {
        if(stalls[i] - last_cow >= sep)
        {
            last_cow = stalls[i];
            count++;
            if(count == cows)
            {
                return true;
            }
        }
    }

    return false;
}

int findcows(vector <int> &stalls , int n , int cows)
{
    int start = 1;
    int end = stalls[n-1] - stalls[0];
    int res;

    while(start <= end)
    {
        int mid = (start + end)/2;

        if(verify(stalls,n,cows,mid))
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    int cows;
    cin >> cows;

    vector <int> stalls(n);

    for(int &i : stalls)
    {
        cin >> i;
    }

    sort(stalls.begin(),stalls.end());

    cout << findcows(stalls,n,cows);
    return 0;
}