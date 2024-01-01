#include <iostream>
using namespace std;

const int N = 0;

bool subsets_check(int* in,int*out,int i,int j,bool status,int n){
	// if(j==0)return false;

	if(i==n){
		int sum = out[0];
		for(int k = 1 ; k < j ; k++){
			sum+=out[k];
		}
		if(sum==0){
			status = true;
		}
		return status;
	}

	// rec case
	// calling with ith element
	out[j]=in[i];
	bool a = subsets_check(in,out,i+1,j+1,status,n);

	// calling w/o ith element
	bool b = subsets_check(in,out,i+1,j,status,n);
	return (a | b);
}
int main(){

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		int in[n];

		for (int i = 0; i < n; ++i){
			cin >>in[i];
		}

		int out[n];
		if(subsets_check(in,out,0,0,false,n)){
			cout << "Yes"<<endl;
		}
		else{
			cout << "No"<<endl;
		}
	}
		return 0;
}