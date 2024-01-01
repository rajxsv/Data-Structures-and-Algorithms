#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define ll long long

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		// int k;
		// cin >> k;

		int mod[n];
		memset(mod,0,sizeof(mod));

		ll arr[n];
		ll sum = 0;

		for (int i = 0; i < n; ++i){
			cin >> arr[i];	
			sum += arr[i];
			//we keeep adding the reminder to our mod array 
			//based on pigeon hole concept 
			ll rem = ((sum%n)+n)%n;
			mod[rem]++;
		}

		ll res = 0;

		for (int i = 0; i < n; ++i){
			if(mod[i]>1){
				res+=(mod[i]*(mod[i]-1))/2;        //nC2 thing
			}
		}

		//adding the numbers divisble by k itself

		res += mod[0];

		cout << res<<endl;
	}


	return 0;
}