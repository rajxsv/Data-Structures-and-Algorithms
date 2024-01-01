#include<iostream>
using namespace std;

#define ll long long

// modulo property that (a^b)%m = ((a%m)(b%m))%m

ll MyPow(ll a , ll b , ll c)
{	
	a = a % c;

	ll ans = 1;
	
	// this loop is fast power exponentiation loop so try to understand this
	while(b>0)	
	{	
		ll mask = b & 1;

		if(mask)
		{	
			// just like explained this 'ans'
			 // also has to be with reoititive mods 
			ans = (ans*a)%c; 
		}
		// update acc to the modulo property again
		a = (a*a)%c; 
		b >>= 1;
	}

	return ans;
}
int main()
{
	ll a , b , c;
	cin >> a >> b >> c;

	//first i need a^b 

	ll temp = MyPow(a,b, c); 

	cout << temp;

	return 0;
}