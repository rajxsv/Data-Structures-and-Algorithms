#include <iostream>
using namespace std;

const int N = 0;

int place(int n,int m)
{
	// base case
	if(n<=0)return 0;

	if(n==1)return 1;

	if(n==m)return 2;

	// rec case
	return place(n-1,m) + place(n-m,m);
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n,m;
		cin >> n >> m;

		cout << place(n,m)<<endl;
	}

	return 0;
}