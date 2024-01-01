#include <stdio.h>
void merge(int* arr , int s , int e,int n)
{
	int mid = (s+e)/2;
	int k = s;  // new array pointer
	int i = s;	// divided array pointers
	int j = mid+1;

	int temp[n]; //new array to store elements for each stack

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

	//we also need to copy the elements in the arr 
	for (int i = s; i <= e; ++i){
		arr[i] = temp[i];
	}

}

void merge_sort(int* arr,int s,int e,int n){
	// base case
	if(s>=e){
		return;
	}
	int mid = (s+e)/2;

	merge_sort(arr,mid+1,e,n);
	merge_sort(arr,s,mid,n);
	merge(arr,s,e,n);
}

int main()
{
	int n;
	scanf("%d",&n);

	int arr[n];

	for (int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
	}

	merge_sort(arr,0,n-1,n);

	for (int i = 0; i < n; ++i){
		printf("%d ",arr[i]);
	}

	return 0;
}