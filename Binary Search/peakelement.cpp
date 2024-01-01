#include<bits/stdc++.h>
using namespace std;
int peakr(int arr[],int n)
{
    int start = 0 , end = n - 1;
    while(start<=end)
    {
        int mid = ( start + end )/2;

        if(mid > 0 && mid < n-1)
        {
            
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid-1])
                return mid;

            //greedy huh    !!!
            else if(arr[mid - 1]>arr[mid])
                end = mid - 1;
                                                                                                                                                                            

            else if (arr[mid + 1]>arr[mid])
                start = mid + 1;
           
        }
    }
    return arr[n-1];
}
int main()
{
    /*for nearly sorted array
   int arr[]= {5,10,20,15};*/
   //for bitonic array 
   int arr[]={1,2,3,4,5,90,23,10,3};

   int n = sizeof(arr)/sizeof(arr[0]);
   cout << peakr(arr,n);
  
    return 0;
}