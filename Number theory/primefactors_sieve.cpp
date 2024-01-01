#include<bits/stdc++.h>
using namespace std;

#define ll long long

void prime_sieve(ll arr[])
{
	//first we mark all odds as prime
	for(ll i = 3 ; i < 100000 ; i+=2)
	{
		arr[i] = 1;
	}

	//now we traverse the odds and remove all the primes following i*i and ahead of it 

	for(ll i = 3 ; i <= 100000 ; i+=2)
	{
		if(arr[i])
		{
			for(ll j = i*i ; j< 100000 ; j += 2*i)
			{
				arr[j] = 0;
			}
		}
	}

	arr[0] = 0;
	arr[1] = 0;

	arr[2] = 1;
}

void primefactors(ll prime[],int n)
{	
	vector <pair<int,int>> factors;
	int count;
	//visiting every prime for operations
	for(int i = 0 ; i < n ; i++){
		//chcking if prime
		if(prime[i]){	
			count = 0;
			//whether that dividees my number or not
			if(n%i == 0){
				// keep dividing the number
				while(n%i == 0){
					count++;
					n/=i;
				}

				factors.push_back(make_pair(i,count));
			}
		}
	}

	if(n!=1){
		factors.push_back(make_pair(n,1));
	}

	for(auto i : factors)
	{
		cout << i.first << "^" << i.second << endl;
	}
}

int main()
{
	int n;
	cin >> n;

	ll prime[100000] = {0};

	prime_sieve(prime);
	primefactors(prime,n); 
	
	return 0;
}