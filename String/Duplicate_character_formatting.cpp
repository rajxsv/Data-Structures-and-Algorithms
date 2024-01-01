#include <iostream>
using namespace std;

const int N = 0;

void fun(string &s , string &ans,int i)
{	
	// base case
	if(i == (s.length()))
	{
		return;
	}
	// rec case

	ans += s[i];

	if(s[i] == s[i+1])
	{
		ans += '*';
	}

	fun(s,ans,i+1);

}


int main()
{
	string s ;
	cin >> s;

	string ans;
	fun(s,ans,0);

	cout << ans;



	return 0;
}
