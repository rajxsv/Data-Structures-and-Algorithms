#include <iostream>
using namespace std;

const int N = 0;
int key = 40;

void binary_search(int arr[] , int start , int end){
	int mid = (start+end)/2;

	if(arr[mid]>key){
		binary_search(arr,start,mid-1);
	}
	else if(arr[mid]<key){
		binary_search(arr,mid+1,end);
	}
	else{
		cout << "Element present at "<< mid <<" index"<<endl;
	}
}

int main(){
	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	binary_search(arr,0,n-1);

	return 0;
}