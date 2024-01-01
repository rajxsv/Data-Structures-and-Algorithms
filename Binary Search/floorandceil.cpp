#include<bits/stdc++.h>
using namespace std;

int floor(int arr[] , int n,int k)
{
    int start = 0,end = n - 1;
    int res=-1;
    while(start <= end)
    {

        int mid = start + ((end - start)/2);
        
        if(arr[mid]==k)return arr[mid];
        if(k > arr[mid])
        {
            res = arr[mid];
            start = mid + 1;
        }

        else if (k < arr[mid])
        end = mid - 1;
    
    }

    return res;
}
int ceil(int arr[] , int n,int k)
{
    int start = 0,end = n - 1;
    int res=-1;
    while(start<=end)
    {
        int mid = start + ((end - start)/2);

        if(arr[mid]==k)
        return arr[mid];
        
        if(k > arr[mid])
        start = mid + 1;
        

        else if (k < arr[mid])
        {
            res = arr[mid];
            end = mid - 1;

        }       


    }

    return res;
}
int  main()
{
     int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"now input k"<<endl;
    int k ;
    cin >> k;

    cout << "floor " << floor(arr,n,k)<<endl;
    cout << "Ceil " << ceil(arr,n,k);


    return 0;
}