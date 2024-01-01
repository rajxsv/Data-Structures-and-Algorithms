#include<iostream>
using namespace std;
bool prime_check(int n){
     for (int i=2 ; i<(n-1) ; i++){
         if (n%i==0){
             return false;
         }
     }
     return true;
}

void printer(int n){
    for(int i =2 ; i<=n ; i++){
       if(prime_check(i)){
       cout << i << " ";
       }
    }
}

int main(){
    int n;
    cin >> n;
    printer(n);

}
