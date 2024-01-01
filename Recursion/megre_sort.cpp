#include <iostream>
using namespace std;

const int N = 0;

void merge(int* arr , int s , int e,int n){
	//here the asssumption is we already have 3 sorted arrays 
	// from s to mid and mid + 1 to e
	int mid = (s+e)/2;

	// new array pointer
	int k = s;

	// divided array pointers
	int i = s;
	int j = mid+1;

	int temp[n];

	while(i <= mid && j <= e){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
		}
		else {
			temp[k++]=arr[j++];
		}
	}
	// in case any of them is left empty
	while(i<=mid)temp[k++]=arr[i++];

	while(j<=e)temp[k++]=arr[j++];

	//we also need to copy the elements in 
	for (int i = s; i <= e; i++){
		arr[i] = temp[i];
	}

}

void merge_sort(int* arr,int s,int e,int n){
	// base case
	if(s>=e){
		return;
	}

	int mid = (s+e)/2;
	
	merge_sort(arr,s,mid,n);//and the first part
	merge_sort(arr,mid+1,e,n);//rec sort the second part

	merge(arr,s,e,n);
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

	merge_sort(arr,0,n-1,n);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i]<<" ";
	}

	return 0;
}