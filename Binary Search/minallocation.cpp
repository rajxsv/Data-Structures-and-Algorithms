// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    //Function to find minimum number of pages.
    bool verify(int A[] , int mid , int M , int N)
    {
        int sum = 0; 
        int mcount = 1;
        
        for(int i = 0 ; i < N ; i++) 
        {
            if(A[i]+sum <= mid)
            {
                sum += A[i];
            }
            else
            {
                mcount++;
                if(A[i]>mid || mcount > M)  {
                    return false;
                }
                sum = A[i];
            }
        }
                
        return true;    
    }
    
    int findPages(int A[], int N, int M) 
    {
          //code herE
        int sum = 0;
        int max = INT_MIN;
        
        for(int i =0; i < N; i++)
        {
            sum+=A[i];
            if(A[i]>max)max = A[i];
        }
       
        int start = max , end = sum;
        int res = -1;
        
        while(start <= end)
        {
            int mid = start + ((end - start)/2);
            
            if(verify(A,mid,M,N))
            {
                res = mid;
                cout << res << " ";
                end = mid - 1;
            }
            
            else 
            {
                start = mid + 1;
            }
            
        }
        cout << endl;
        
        return res;
    }
};
// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends  