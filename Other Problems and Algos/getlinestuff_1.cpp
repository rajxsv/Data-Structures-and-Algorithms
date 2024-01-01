#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    // taking string as input and keeping a deliminator *

    string s;
    getline(cin, s, '*');
    cout << s << endl<< s.length(); // here return value of s.length is int

    
    // taking char[ ] as input and kee[ing * as delimnator

    char a[10];
    
    //this consumes upto \n , basically [start,\n)
    //you can use cin.get to flush that \n cin.get() 
    // char ch=cin.get();
    
    cin.getline(a, 5, '*');
    cout << a << sizeof(a); // here return value of char array is size_t

    cout<<endl<<endl;
    

    return 0;
}