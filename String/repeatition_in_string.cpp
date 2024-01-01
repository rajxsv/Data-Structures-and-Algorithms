#include<bits/stdc++.h>
using namespace std;

int main() 
{
	vector <char> arr;
	int i = 0;
	char ch = cin.get();

	while(ch!='\n')
	{
		arr[i]=ch;
		i++;

		ch = cin.get();
	}
    
	sort(arr.begin(),arr.end());
	int max = INT_MIN;
	char ans ='a';
	int count = 0;

	int j = 0;
	while(j<i-1)
	{
		while(arr[j]==arr[j+1])
		{
			count++;
		}
		if(count > max)
		{
			ans = arr[j];
		}
	}

	cout << ans ;

	return 0;
}