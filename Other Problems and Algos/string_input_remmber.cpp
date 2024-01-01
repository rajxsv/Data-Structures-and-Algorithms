#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    // taking string as input and keeping a deliminator *

    string s;
    getline(cin, s, '*');
    cout << s << endl
         << s.length(); // here return value of s.length is int

    cout << endl
         << endl;
    // taking char[ ] as input and kee[ing * as delimnator

    char a[1000];
    
    //this consumes upto \n , basically [start,\n)
    //you can use cin.get to flush that \n cin.get() 
    cin.getline(a, 1000, '*');
    cout << a << sizeof(a); // here return value of char array is size_t

    return 0;
}