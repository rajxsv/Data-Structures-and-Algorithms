
#include<iostream>
using namespace std;
int fibseries(int n){
    int a=0,b=1,c;
    if(n==0){
    return a;
    }
    for(int i = 2; i<=n ; i++){
        c=a+b;
        a=b;
        b=c;
        
    cout << a << " ";
  }
  return 0;
}

int main(){
    int n;
    cin >> n;
    
    fibseries(n);
    return 0;
}