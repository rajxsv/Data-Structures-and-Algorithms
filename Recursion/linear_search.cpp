#include <iostream>
using namespace std;

const int N = 10;
int key = 12;

int myFind(int arr[],int n,int i)
{
	if(n==i)return -1;

	if(arr[i]==key)
	{
		return i ;
	}	

	return myFind(arr,n,i+1);
}

int main()
{
	int arr[N] = {5,2,44,22,14,12,15,15,43,12};

	cout << myFind(arr,N,0);

	return 0;
}