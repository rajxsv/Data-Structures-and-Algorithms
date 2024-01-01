#include<iostream>
#include <algorithm>
#include<string>
using namespace std;

bool compare(int a,int b){
	string x = to_string(a);
	string y = to_string(b);

	return x>y;
}

int main(){
	int t,n;
	cin >> t;

	while(t--){
		cin >> n;

		int arr[n];

		for (int i = 0; i < n; ++i){
			cin >> arr[i];
		}
		sort(arr,arr+n,compare);
		// form(arr,n);
		for (int i = 0; i < n; ++i){
			cout<<arr[i];
		}

	}
}