#include<bits/stdc++.h>
using namespace std;

void primefactors(int n)
{
	//a loop for each number to check till root n
	vector <pair<int,int>> factors;
	int power;

	// i*i as that basic observaton that factors occcur in pairs
	for (int i = 0; i*i <= n; ++i)
	{
		power = 0;
		// if a number divides then dividing furthur 
		if(n%i == 0)
		{
			while(n%i)
			{
				power++;
				n/=i;
			}

			factors.push_back(make_pair(i,power));
		}
	}

	// if n is still not 1 then it itself is a prime
	if(n!=1)
	{
		factors.push_back(make_pair(n,1));
	}

	for(int i = 0 ; i < factors.size() ; i++)
	{
		cout << factors[i].first << "^" <<factors[i].second <<endl;
	} 

}

int main()
{
	int n;
	cin >> n;

	primefactors(n);
	return 0;
}