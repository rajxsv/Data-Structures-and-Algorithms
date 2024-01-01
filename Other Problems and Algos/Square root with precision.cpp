#include<iostream>
using namespace std;
int main(){
    float n;
    float dec=1;
    float ans=0;
    int pre;
    cin>>n>>pre;

      for(int times=0 ; times<=pre ; times++ )   {

            while(ans*ans<=n){
            ans = ans + dec;

            }
            ans=ans-dec;
            dec = dec/10;

      }     
      cout<<ans;





return 0;
}