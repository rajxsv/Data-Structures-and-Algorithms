#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 0;

void convert(string s,int* ptr,int i)
{
	// base case
	if(i==s.length())return;

	// rec case
	*ptr = (*ptr)*10 + ((int)(s[i]-'0'));
	convert(s,ptr,i+1);
}

int main()
{
	string str;
	cin >> str;

	int ans=0;

	convert(str,&ans,0);

	cout << ans;

	return 0;
}