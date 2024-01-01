#include <iostream>
#include <string.h>
using namespace std;

const int N = 0;

string fun(string s)
{
	// base case
	if(s.length()==0 || s.length()==1)
	{
		return s;
	}

	// rec case

	if(s[0]=='x')
	{
		return fun(s.substr(1)) + s[0];
	}

	return s[0] + fun(s.substr(1));
	
}

int main()
{
	string s;
	cin >> s;

	cout <<fun(s);

	return 0;
}