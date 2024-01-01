#include<bits/stdc++.h>
using namespace std;


/*

floor(x) :
Returns the largest integer that is smaller than or equal to x (i.e : rounds downs the nearest integer).

ceil(x) : 
Returns the smallest integer that is greater than or equal to x (i.e : rounds up the nearest integer).


lower_bound :
returns an iterator pointing to the first element in the range [first,last) which has a value greater than or equal to ‘val’. 
first element greater than equal to val

and if the value is not present in the vector then it returns the end iterator.

upper_bound:
returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. 
first element strictly grreater than value


*/

int first(int arr[], int n,int k)
{
    int start = 0;
    int end = n - 1;
    int mid,res;
    while(start<=end){
        
        mid = start - ((start - end) >> 2);
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
    cout << "first occurence" << first(arr,n,k) << endl;
    cout << "last occurence" << last(arr,n,k);
    return 0;
}