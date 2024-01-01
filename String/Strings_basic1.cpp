#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s0 = ("s0");
    string s1("s1");
    // string s2[]={'s','two','\0'};       ***Not in c++***
    // string s3[3]={'s','three','\0'};          //
    string s4 = ("s4");
    char a[4] = {'a', 'b', 'c', '\0'};
    string s5(a);
    string s6; // not initialised is a null string
    cout << s0 << endl
         << s1 << endl
         << s4 << endl
         << s5 << endl;
    if (s6.empty())
    {
        cout << "s6 is empty" << endl;
    }
    s6.append("hmmmm"); // adding a string to a predefined string
    cout
        << s6 << endl;
    s6 += " and so is my brain";
    cout << s6 << endl;
    cout << "LEngth OF S6 is " << s6.length() << endl;
    s6.clear();
    cout << "length of s6 is " << s6.length() << endl;
    cout << s6.compare(s1) << endl;
    string s7 = "raj";
    string s8 = "didi";
    if (s7 > s8) // compared lexographically
    {
        cout << "s7 is greater than s8" << endl;
    }
    else if (s8 > s7)
    {
        cout << "s8 is greater than s7" << endl;
    }
    string s9 = "its a lovely night";

    s9.erase(s9.begin() + 5); // erasing something present at this particular index
    cout << s9 << endl; 
    

    

    s9.erase(2 , 5); // erasing everything between these two index
    cout << s9 << endl;
    s9.erase(1); // erasing every element except this index
    cout << s9 << endl;

    // more types

    s9 = "its a lovely night";
    int index = s9.find("night"); // finding a word (gives the starting index of that word)

    cout << "The index of night is " << index << endl;

    string x = "night";   // string word = "night";
    int len = x.length(); // remember this takes int as parameter   // length of a string

    s9.erase(index, len); // ersae takes its parameters from int index to int index(the one 'till' we have to do)

    cout << s9 << endl; 
    for (auto c : s8)
    {
        cout << c << ",";
    }
    cout << endl;
    for (auto it = s8.begin(); it != s8.end(); it++)
    {
        cout << (*it) << ".";
    }
    // READING N SENTENCES
    string s[100];
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }

    sort(s, s + n); /// refer to string random problem program
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }

    cout << s << endl; // hmmmmmm interesting,,,this only happens if declaring s1 in this specific type as it is now being treated as array
    return 0;
}