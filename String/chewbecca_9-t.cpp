#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        
        if(s[0] - '0' == 9)
        {
            continue;
        }

        else if(s[i] - '0' >= 5)
        {
            s[i] = 9 - (s[i] - '0') +'0';
        }
    }

    cout << s;
    return 0;
}