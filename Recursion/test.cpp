#include <iostream>

using namespace std;

int main()
{ 
   int arr[4][4];
   
   cout <<"take input";
   for(int i=0; i<4; i++)
   {
       for (int j=0; j<4; j++)
       {
           cin>>arr[i][j];
       }
   }
   
   cout<<"print the array sine format";

    for (int j=0; j<4; j++)
       {
           if(j%2==0)
           {
               for(int i=0; i<4; i++)
               {
                   cout<<arr[i][j]<<" ";
               }
               cout<<endl;
           }
           else
           {
               for(int i=3; i>=0; i--)
               {
                   cout<<arr[i][j];
               }
               cout<<endl;
           }
          
       }
   



   
    

    return 0;
}