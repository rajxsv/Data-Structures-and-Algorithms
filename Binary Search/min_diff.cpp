#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int n , int k)
{
    int start = 0 , end = n-1;
    while(start <= end)
    {   
        int mid = start + ((end - start)/2);
        if(arr[mid]>k)
        {
            end = mid - 1;
        }
        else if (arr[mid]<k)
        {
            start = mid + 1;
        }

    }
    
    if((abs(arr[start]-k))>(abs(arr[end]-k)))
    {
        return end;
    }

    else
    {
        return start;
    }

}
int main()

{
    int n,k;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    cout <<"key??";
    cin >> k;
    cout << binary(arr,n,k);
    return 0;
}