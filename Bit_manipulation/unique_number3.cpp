#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);

	vector<int> bit(64);
	int k = 63;
	
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> v[i];

		int temp = v[i];
		int j = k;
		while(temp>0){
			bit[j] += temp & 1; //storing bit
			j--;
			temp = temp >> 1;
		}

	}

	
	int ans = 0;
	for (int i = 63; i >= 0; --i){
		ans = ans + (bit[i]%3)*(pow(2,(63 - i))); //simply making the binary to decimal
	}

	cout << ans;
	return 0;
}
