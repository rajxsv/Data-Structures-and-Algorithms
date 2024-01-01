#include <bits/stdc++.h>
using namespace std;

const int N = 0;

void bubble_sort(int* arr , int j , int n)
{
	// base cases
	if(n==1)return;

	if(j==n-1)return bubble_sort(arr,0,n-1);

	// rec case
	if(arr[j] > arr[j+1])
	{
		swap(arr[j],arr[j+1]);
	}
	bubble_sort(arr,j+1,n);

	return;
}

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for(int i = 0 ; i < n ; i++)
	{
		cin >> arr[i];
	}

	bubble_sort(arr,0,n);

	for(int i = 0 ; i < n ; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}