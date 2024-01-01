#include<bits/stdc++.h>
using namespace std;
int rotate(int arr[] , int n)
{
    int low = 0 ; 
    int mid , next , prev;
    int high = n - 1;

    while(low <= high){
        mid = high + ((low - high)/2);
        next = (mid+1+n)%n;
        prev = (mid - 1 + n)%n;
        
        if(arr[mid] <= arr[next] && arr[mid]<=arr[prev])
            return mid;
        else if(arr[mid] >= arr[low])
            low = mid + 1;  
        else if(arr[mid] <= arr[high])
            high = mid - 1;  

    }
    return 0 ;
}
int binarysearch(int arr[],int start , int end , int k)
{

    while(start < end)
    {
        int mid = start +((end - start)/2);
        if(arr[mid]==k)
        return mid;

        else if (k > arr[mid])
        start = mid + 1;

        else if ( k < arr[mid])
        end = mid - 1;

    }
    
    return -1;

}
int main()
{
    int n,k;
    int arr1[] = { 15, 18, 2, 3, 6, 12 };
    int arr[] = {7, 9, 11, 12, 5};

    k = 9;
    n = sizeof(arr1)/sizeof(arr1[0]); 
    int n1 = sizeof(arr)/sizeof(arr[0]);
    int i = rotate(arr,n1);
    cout << "its is rotated " << i << " times"<<endl;
    int ans1 = binarysearch(arr,i,n-1 , k);
    int ans2 = binarysearch(arr,0,i-1 , k);

    if(ans1>=0){
        cout << ans1 <<endl;
    }
    
    else
    {
        cout <<ans2<<endl;
    }
    
    return 0;
}