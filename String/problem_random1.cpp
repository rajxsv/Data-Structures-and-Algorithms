#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1;
    getline(cin, s1 );
    reverse(s1.begin(),s1.end());
    cout << s1;

    return 0;
}
