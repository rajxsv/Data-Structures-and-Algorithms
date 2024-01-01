#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,y;
	cin >> x >> y;

	int xr = 0;

	for(int i = x ; x <= y ; x++)
	{
		for(int j = x ; x <= y ; y++)
		{
			xr = max(xr,i^j);
		}
	}

	cout << xr;

	return 0;
}