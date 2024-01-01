#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;

	//a is the no and b is the power
	int ans = 1;

	while(b>0)
	{
		int mask = b & 1;

		if(mask)
		{
			ans *= a;
		}

		b = b >> 1;
		a*=a;
	}
	cout << ans;




	return 0;
}