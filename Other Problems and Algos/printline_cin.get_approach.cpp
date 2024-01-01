#include<iostream>
using namespace std;
//using cin,get to read a sentence till we get \n
void printline(char a[] , int max_length)
{
    int i = 0;
    char ch = cin.get();
    while(ch!= '$'){
        a[i]=ch;
        i++;

        if(i==max_length-1)
                
        {
            break;
        }

        ch = cin.get();
      
    }

    a[i]='\0';
    return ;
}
int main(){

    char a[1000];
    printline(a,1000);
    cout << a <<endl;
    return 0 ;
    
}