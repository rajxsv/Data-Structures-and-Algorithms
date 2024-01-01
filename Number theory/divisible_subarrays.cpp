#include<iostream>
#include<vector>
using namespace std;

// THIS APPROACH EXCEEDS TIME LIMIT!

#define ll long long

int main()
{
	ll t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;

		vector<ll> v(n);
		vector<ll> c(n);

		cin >> v[0];
		c[0] = v[0];

		for (ll i = 1; i < n; ++i){
			cin >> v[i];
			c[i] = v[i] + c[i-1];
		}

		ll count = 0;
		// we now find the sum we desire
		for (ll i = 0; i < n; ++i){
			for(ll j = i ; j < n ; j++){
				ll sum = 0;

				if(i==0){
					sum = c[j];
				}
				else{
					sum = c[j] - c[i-1];
				}
				if(sum%n == 0){
					count++;
				}
			}
		}

		cout << count <<endl;
	}


	return 0;
}