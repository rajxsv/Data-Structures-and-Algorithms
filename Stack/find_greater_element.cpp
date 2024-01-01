#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector <int> arr;
	int data;
	
	for(int i=0;i<n;i++){
		cin>>data;
		arr.push_back(data);
	}

	for(int i=0;i<n-1;i++){
		arr.push_back(arr[i]);
	}

	stack <int> s;

	for(int i=0;i<n;i++){
		if(s.empty() ||s.top()>=arr[i]){
			s.push(arr[i]);
		}
		else{
			cout<<arr[i]<<" ";
			s.pop();
			s.push(arr[i]);
		}
	}

	while(!s.empty()){
		cout<<-1<<" ";
		s.pop();
	}
}


//BELOW IMPLEMENTATION IS BRUTE FORCE

// int main(){
// 	stack<int> s;
// 	int n;
// 	cin>>n;

// 	vector<int> v;
// 	int data;
// 	for(int i=0;i<n;i++){
// 		cin>>data;
// 		v.push_back(data);
// 	}
// 	v.insert(v.begin(),v.begin(),v.end());
// 	v.pop_back();
	
// 	for(int i=0;i<n;i++){
// 		int j=i;
// 		bool flag=true;
// 		for(;j<v.size();j++){
// 			if(v[j]>v[i]){
// 				cout<<v[j]<<" ";
// 				flag=false;
// 				break;
// 			}
// 		}
// 		if(flag){
// 			cout<<-1<<" ";
// 		}
// 	}

// }