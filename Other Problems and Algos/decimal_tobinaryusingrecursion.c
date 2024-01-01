#include<stdio.h>

int binary(int n){
    static int ans = 0;
    
     ans = (n%2) + ans*10;

     if(n/2>0){
        binary(n/2);
     }
     else{
         return ans ;
     }
    
    return ans ;
}
int main(){
    int n;

    scanf("%d",&n);
    printf("%d",binary(n));

    return 0 ;
}