#include <bits/stdc++.h>

using namespace std;

int main()
{ // int the first call we pass the string as arguement and in sunsequent calls we pass'NULl' when calling strtok
    char s[] = "Dayum Today is a goodday ";
    char a1 = 'l';
    string a2 = "a1 asdijkjgjyytjcaergdkjwnfen";
    cout << a1 << endl
         << a2 << endl  //the memory alloted to char[ ] remains constant zso this will always be 32 
         << s << endl;
    cout << sizeof(a1) << endl
         << sizeof(a2) << endl
         << sizeof(s) << endl; // the char by default has 1 bit



         
    char *ptr = strtok(s, " ");

    cout << ptr<<endl;
    while (ptr != NULL)
    {
        ptr = strtok(NULL, " ");
        cout << ptr << endl;
    }
    return 0;
}