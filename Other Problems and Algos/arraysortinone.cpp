#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int a[100];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    
    if(a[0]%2!=0){
        for(int i = 1 ; i < n ; i++){
            int temp = i;
            if(a[i]%2!=0){
                continue;
            }
            else{
                
                while(a[temp]%2==0){
                    swap(a[temp],a[temp+1]);
                    temp++;
                }
                swap(a[i],a[temp]);
            }
        }
    }
    else{
        for(int i = 1 ; i < n ; i++){
            int temp = i;
            if(a[i]%2==0){
                continue;
            }
            else{
                
                while(a[temp]%2!=0){
                    swap(a[temp],a[temp+1]);
                    temp++;

                }
                swap(a[i],a[temp]);
            }
        }

    }
    


    return 0;
}
