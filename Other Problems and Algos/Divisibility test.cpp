#include <iostream>
using namespace std;

int main(){

int n;
cin >> n;
    
     if (n%2==0 && n%3==0){
        cout << n <<" is divisble by 2 and 3"<<endl;
          }


                else if(n%2==0){
                   
                   cout << n <<" is divisible by 2 only" << endl;

                }
                else if (n%3==0){

                   cout << n << " is divisible by 3 only" << endl;

                
                }   
        else{
             cout << "number is neither divisble by 2 nor 3"<<endl;

            }       
	
}
