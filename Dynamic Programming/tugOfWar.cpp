#include<iostream>
#include<cstring>
using namespace std;

int ans = INT_MAX;

void tugOfWar(int arr[],int n,int idx,bool taken[],int freq){
    if(idx==n){
        return;
    }

    if(freq == n/2){
        int sum1=0;
        int sum2=0;

        for(int i=0;i<n;i++){
            if(taken[i]){
                sum1+=arr[i];
            }else{
                sum2+=arr[i];
            }
        }
        if(abs(sum1-sum2)<ans){
            ans = abs(sum1-sum2);
        }
        return;
    }
    if(freq<n/2){
        tugOfWar(arr,n,idx+1,taken,freq);
        taken[idx]=true;
        tugOfWar(arr,n,idx+1,taken,freq+1); 
        taken[idx]=false;
    }

}

int main(){

    int arr[] = {3, 4, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool taken[n];
    
    memset(taken,false,sizeof(taken));
    tugOfWar(arr, n,0,taken,0);

    cout<<ans<<endl;

    return 0;
}