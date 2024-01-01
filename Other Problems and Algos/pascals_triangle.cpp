#include<iostream>
using namespace std;

int binomial(int n,int r){
	if(n==0 || r==0 || n-r == 0){
		return 1;
	}
	int ans;
				

}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<binomial(i,j)<<" ";
		}
		cout<<endl;
	}
}