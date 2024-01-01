#include<bits/stdc++.h>
using namespace std;

#define ll long long

//we will be working our way around on the fact that for a number n = (2^a)(3^b)
// has (a + 1)(b+1)  divisors  can be proven on copy using simple dry rum

int sum_divs(ll prime[] , int n)
{
	//we find the prime factorization of our number to get the powers
	// although we will only be needing the powers and not numbers

	int ans = 1 ;

	for (int i = 0; i <= n ; ++i)
	{
		int cnt = 0;

		if(prime[i])
		{
			if(n%i == 0)
			{
				while(n%i == 0)
				{
					cnt++;
					n/=i;
				}

				ans *= (cnt + 1);
			}
		}
	}

	if(n!=1)
	{
		ans *= 2;
	}
	return ans;

}

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

int main()
{
	int n;
	cin >> n;

	// we need a sieve first
	ll prime[1000000] = {0};

	prime_sieve(prime);

	//now we can code for the divisors

	cout << sum_divs(prime,n);

	return 0;
}