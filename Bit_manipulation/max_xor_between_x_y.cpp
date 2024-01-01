#include<iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
   //method 1 - (not efficient)
	int x,y;
	cin >> x >> y;

	int xr = 0;

	for(int i = x ; i <= y ; i++)
	{
		for(int j = x ; j <= y ; j++)
		{
			xr = max(xr,i^j);
		}
	}
	cout <<"using method 1 " << xr << endl;

	//we try to find the most left 1 
	//as that
	
	int lxr = x^y;
	int idx = 0;
	while(lxr>0){
		lxr = lxr >> 1;
		idx++;
	}

	// idx;
	// ! max possible set bits in l^r
	cout << pow(2,idx) - 1;
	
	return 0;
}