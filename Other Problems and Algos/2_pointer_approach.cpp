#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,key,a[8]={1,3,5,7,10,11,12,13};
    key = 16;
    int i = 0;
    
    int j = sizeof(a)/sizeof(int)-1;
        while(j>i){
            
            int current_sum = a[i]+a[j];

            if(current_sum>key){
                j--;
            }
            else if(current_sum<key){

                i++;
            }
            else if(current_sum==key){
                cout<<a[i]<<" and "<<a[j]<<endl;
                j++;
                i++;
            }
            
        }
    

    return 0;
}