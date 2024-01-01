#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 0;

void print(vector <string> &s , int n)
{
	// base case
	if(n==0)return;

	// rec case
	print(s,n/10);
	cout << s[n%10]<<" ";
}

int main()
{
	int n;
	cin >> n;

	vector <string> s {"zero","one","two","three","four","five","six","seven","eight","nine"};
	print(s,n);

	return 0;
}