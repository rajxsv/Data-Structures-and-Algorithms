#include <iostream>
#include <deque>

using namespace std;
int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int a[n];
		for (int i = 0; i < n; ++i){
			cin>>a[i];
		}

		int k;
		cin>>k;
		
		deque<int> q;
		
		for(int i=0;i<k;i++){
			while(!q.empty() && a[i]>a[q.back()]){
				q.pop_back();
			}
			q.push_back(i);
		}

		for(int i=k;i<n;i++){
			cout<<a[q.front()]<<" ";
			//way to refresh so that we dont go outside bounds
			while((!q.empty()) && (q.front() <= (i-k))){
				q.pop_front();
			}
			//a step required as per algorithm
			while(!q.empty() && a[i] >= a[q.back()]){
				q.pop_back();
			}
			q.push_back(i);
		}

		cout<<a[q.front()];
		cout<<endl;

	}
	return 0;
}
