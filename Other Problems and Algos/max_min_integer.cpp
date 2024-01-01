#include<iostream>
#include<climits>
using namespace std;
int main(){
     int int_max=INT_MIN;
     int int_min=INT_MAX;
     int n;
     int no;
     cin >> n;

     for(int i=0 ; i<n ; i++){
         cin >> no;
         if(no<int_min){
             int_min=no;

             }
         if(no>int_max ){
            int_max=no;
                     
         }
         
          
     }cout << "largest number is   " << int_max << endl <<" The smallest number is  "<< int_min;



  


    return 0;
}