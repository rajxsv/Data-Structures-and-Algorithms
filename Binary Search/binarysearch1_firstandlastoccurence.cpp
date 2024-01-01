#include<bits/stdc++.h>
using namespace std;
int first(int arr[], int n,int k)
{
    int start = 0;
    int end = n - 1;
    int mid,res;
    while(start<=end)
    {
        mid = start - ((start - end)/2);
        if (arr[mid]==k)
        {
            res = mid;
            end = mid - 1;
        }
        else if(arr[mid] < k)
        {
            start = mid + 1;
        }
        else if(arr[mid] > k)
        {
            end = mid - 1;
        }
    }
    return res;
}
int last(int arr[],int n,int k)
{
    int start = 0;
    int end = n - 1;
    int mid,res;
     while(start<=end)
    {
        mid = start - ((start - end)/2);
        if (arr[mid]==k)
        {
            res = mid;
            start = mid + 1;
        }
        else if(arr[mid] < k)
        {
            start = mid + 1;
        }
        else if(arr[mid] > k)
        {
            end = mid - 1;
        }
    }
    return res;
}
int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int x = first(arr,n,k) , y = last(arr,n,k);
    cout << "first occurence " << x << endl;
    cout << "last occurence " << y <<endl;
    cout << "No. of times it is present " << y - x + 1 << endl;
    return 0;
}