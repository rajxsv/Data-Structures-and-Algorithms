#include <iostream>
using namespace std;

// using void statements helped to dodge writing another return statement

const int N = 15;

void dec(int n)
{
	if(n==0)
	{
		return ;
	}

	cout << n << " " ;
	dec(n-1);
}

void inc(int n)
{
	if(n==0)
	{
		return ;
	}	

	inc(n-1);
	cout << n << " ";
}	

int main()
{
	int n = N ;
	
	inc(n);

	cout << "\n\n\n\n";

	dec(n);

	return 0;
}