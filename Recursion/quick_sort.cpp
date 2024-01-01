#include <iostream>
using namespace std;

int pivot(int *arr,int s , int e)
{	
	// do not initialise a var for maintaining the pivot as swapping
	// them will not work
	// pointers keeping track of smaller and larger parts
	
	int i = s-1;
	int j = s;

	// function 
	for(;j<=e-1;)
	{
		if(arr[j] <= arr[e])
		{
			i++;
			swap(arr[j],arr[i]);
		}
		j++;
	}
	// putting pivot at the right place
	swap(arr[i+1],arr[e]);

	return (i+1);

}

void quick_sort(int *arr,int s,int e)
{
	// base case 
	if(s>=e){
		return;
    }

	// rec case
	int pvt = pivot(arr,s,e);

	quick_sort(arr,s,pvt-1);
	quick_sort(arr,pvt+1,e);
}

int main()
{
	int n;
	cin >> n;

	int arr[n];
	
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	quick_sort(arr,0,n-1);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] <<" ";
	}	

	return 0;
}