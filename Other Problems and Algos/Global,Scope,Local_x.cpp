#include<iostream>
using namespace std;
int x=100;//global scope x
int main(){
    int x=10;//local scope x (remains same throughout this scope)
if(true){
    x=1;
while(x<5){

     cout << x << " is the loop scope x\n "<<endl;; //the loop scope x 
     x++ ;
     } 

}
        
    cout << x<<" is the local scope x\n"<<endl;;  //local
    cout << ::x<<" is the global scope x\n\n"; //global



    return 0;
}