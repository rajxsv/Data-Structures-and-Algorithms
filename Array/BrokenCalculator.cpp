#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAX 1200
int multiply(int n,int* arr,int arr_size){
	int carry=0;

	for(int i=0;i< arr_size;i++){
		int prod=arr[i]*n+carry;
		arr[i]=prod%10;
		carry=prod/10;
	}

	while(carry){
		arr[arr_size]=carry%10;
		carry/=10;
		arr_size++;
	}
	
	return arr_size;
}	
int main(){

	int n;
	cin>>n;
	int arr[MAX];
	arr[0]=1;
	int arr_size=1;

	for(int i=2;i<=n;i++){
		arr_size=multiply(i,arr,arr_size);
	}

	for(int i=arr_size-1;i>=0;i--){
		cout<<arr[i];
	}
	return 0;
}