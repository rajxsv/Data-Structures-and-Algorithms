#include <bits/stdc++.h>
using namespace std;
int first(int a,int arr[]){
    int n = sizeof(arr) / sizeof(arr[0]);
    int low =0;
    int high= n-1 ;
    int res = 0;
    while(low<=high){
        int mid= high - ((high - low)/2) ;
        if(a==arr[mid]){
            res=mid;
            high=(mid-1);
        }
        else if(a<arr[mid]){
            high= (mid-1);

        }
        else{
            low=(mid+1);
        }
        return res;
    }
}
int main(){
    int arr[]={2,4,10,10,10,18,20};
    cout<<first(10,arr);
}