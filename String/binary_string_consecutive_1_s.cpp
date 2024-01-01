#include <iostream>
#include <vector>
using namespace std;

const int N = 0;

int fun(int n)
{	
	vector<int> v;
	int count = 0;

	for (int i = 0; i < (1<<n) ; ++i)
	{
		int j = i;
		while(j>0)
		{
			if(((j&1) && ((j>>1)&1)))
			{
				break;
			}
			j >>= 1;
		}

		if(j==0)
		{
			count++;
		}
	}

	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << fun(n);

	return 0;
}