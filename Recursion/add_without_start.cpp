#include <iostream>
using namespace std;

const int N = 0;

int multiply(int a,int b)
{
	if(b==1)return a;

	return a + multiply(a,b-1);
}

int main()
{
	int a , b;

	cin >> a >> b;

	cout << multiply(a,b);

	return 0;
}