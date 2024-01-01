#include <iostream>
using namespace std;

#define ll long long

bool check(ll arr[] , ll n){
	if(n==0 || n==1){
		return true;
	}	

	if(arr[0] <= arr[1] && check((arr+1),n-1)){
		return true;
	}

	return false ;
}

int main(){
	ll N ;
	cin >> N;

	ll arr[N];

	for (ll i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	if(check(arr,N))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	

	return 0;
}