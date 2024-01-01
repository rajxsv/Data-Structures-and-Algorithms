#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[n];

	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}	
	sort(arr,arr+n);

	/* for(int i = 0 ; i < n ; i++)
	{
		cout << arr[i]<<",";
	}	 */

	int k=5;
	for(int i = 0 ; i < n-1 ; i++){

		int left = i+1;
		int right = n-1;

		while(left<right){
			int temp = arr[left]+arr[i]+arr[right];
			
			if(temp>k){
				right--;
			}
			else if (temp<k){
				left++;
			}
			else if (temp == k){
				cout << arr[i] << ", "<<arr[left]<<" and "<<arr[right]<<endl;
				left++;
			}
		}
	}

	return 0;
}