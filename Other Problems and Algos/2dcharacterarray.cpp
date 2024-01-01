#include<iostream>
using namespace std;
int main(){
    char c[][100]= {{'a','b','c','\0'},{'d','e','f','\0'}};
    char a[][100]={"abc","def","ghi","jkl"};
    cout << a[1]<<endl<<a[2]<<endl<<a[3]<<endl<<c[1]<<endl<<c[2];
    return 0;
}