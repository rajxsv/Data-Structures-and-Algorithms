#include <bits/stdc++.h>
using namespace std;

int main(){


	int n;
	cin>>n;

	int arr[n];
	int csum[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	csum[0]=arr[0];
	for(int i=1;i<n;i++){
		csum[i]=arr[i]+csum[i-1];
	}

	//FOR A SUBARRAY FROM STARTING ITS CSUM WILL BE 0  so len is i+1
	//only last 0 will be kept
	//otherwise j-i 

	return 0;
}

