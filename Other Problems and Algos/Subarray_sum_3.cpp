#include<bits/stdc++.h>
using namespace std;

int main()
{
    //most efficicent

    int n,sum=0,msum = INT_MIN;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int maxTillNow = 0;
    for(int i = 0 ; i < n ; i++){
        sum+=arr[i];
        
        maxTillNow = max(maxTillNow+arr[i],arr[i]);

        msum=max(maxTillNow,msum);
    }    
    cout << msum;

    return 0;
}