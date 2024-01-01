#include<iostream>
#include<cstring>
using namespace std;
int main(){
    
    char str1[100];
    char str2[100];
    
    // cin.getline() reads input up to '\n' and stops
    // cin.get() reads input up to '\n' and keeps '\n' in the stream

    cin.get(str2 , 100);
    cin.getline(str1 , 100);
    
    cout << str1 << " "<<str2;

    return 0;
}