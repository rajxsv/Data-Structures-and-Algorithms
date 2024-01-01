#include <iostream>
#include <unordered_set>
#include <map>
using namespace std;

bool check(int* arr,int n){
	unordered_set<int> s;
					
	int pre = 0;
	for(int i=0;i<n;i++){
		pre+=arr[i];

		if(pre==0 || s.find(pre)!=s.end()){  
			
			//this end thing basically will not be equal 
			//in a case where PREFIX SUM becomes same as 
			//before at some index and in a case
			// where an element is zero it also covers that
			
			return true;
		}

		s.insert(pre);
	}

	return false;
}

int main(){

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	//brute force takes O(N^3)

	if(check(arr,n)){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}


	return 0;
}
