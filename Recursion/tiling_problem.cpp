#include <iostream>
using namespace std;

const int N = 0;

int tiling(int n)
{
	// base case
	if(n<=3)
	{
		return 1;
	}

	// rec case
	return tiling(n-1) + tiling(n-4);
}

int main()
{
	int n;
	cin >> n;

	cout << tiling(n);

	return 0;
}