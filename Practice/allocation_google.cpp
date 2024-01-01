#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	int x=0;
	while(t--){
		int n;
		cin >> n;
		x++;
		int dollars;
		cin >> dollars;

		int arr[n];
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}

		sort(arr,arr+n);

		int sum=0;
		int count=0;
		for(int i=0;i<n;i++){
			if(dollars-arr[i]>=0){
				dollars = dollars-arr[i];
				count++;
			}
			else{
				cout<<"Case #"<<x<<": "<<count<<endl;
				break;
			}
		}
	}

	return 0;
}