// ------------------------------------Name:Rajpreet Singh 
// ------------------------------------Rno.21104081
#include <stdio.h>
#include <math.h>
int pivot(int arr[],int s , int e){
	int i = s-1;
	int j = s;

	for(;j<=e-1;){
		if(arr[j] <= arr[e]){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j]=temp;
		}
		j++;
	}
	int temp = arr[e];
	arr[e] = arr[i+1];
	arr[i+1]=temp;
	return (i+1);
}

void quick_sort(int arr[],int s,int e)
{

	if(s>=e){
		return;
    }
	int pvt = pivot(arr,s,e);
	quick_sort(arr,s,pvt-1);
	quick_sort(arr,pvt+1,e);
}

int main()
{
	int n;
	scanf("%d",&n);

	int arr[n];
	
	for (int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
	}

	quick_sort(arr,0,n-1);

	for (int i = 0; i < n; ++i){
		printf("%d ",arr[i]);
	}	

	return 0;
}
// ----------------DSA Assignment 4--------------------