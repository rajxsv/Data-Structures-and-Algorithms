#include <iostream>
using namespace std;

const int N = 0;

int myPow(int a , int b)
{
	// base case

	if(b==0)return 1;

	//rec case

	int half = myPow(a,b/2);

	if(b%2==0)
	{
		return half*half;
	}

	return half*half*a;
}

int main()
{
	int a,b;
	cin >> a >> b;

	cout << myPow(a,b);

	return 0;
}