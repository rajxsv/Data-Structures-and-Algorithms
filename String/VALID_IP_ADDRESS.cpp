#include<bits/stdc++.h>
using namespace std;

int converttoint(string s)
{   
    int ans = 0;
    for(int i = 0 ; i < s.length() ; i++)
    {
        ans += (s[i]+'0') + ans*10;
    }

    return ans;
}
int main()
{
    string s;

    

    while(true)
    {
        getline(cin,s,'.');
        int count = 0;
        int num = converttoint(s);
        count++;
        

    }







    
    

    string s;
    cin >> s;
    return 0;
}