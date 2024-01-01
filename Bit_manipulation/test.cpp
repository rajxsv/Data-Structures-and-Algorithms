#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		int arr[n];

		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		while(y--){
			arr[0]^=x;
			int temp=arr[0];
			
			sort(arr,arr+n);
			if(temp==arr[0]){
				break;
			}
		}
		if(y&1 && y>0){
			arr[0]^=x;
		}
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}