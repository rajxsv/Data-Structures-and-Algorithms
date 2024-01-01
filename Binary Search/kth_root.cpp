#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){

		unsigned long long int n,k;
		cin>>n>>k;

		unsigned long long int s=1;
		unsigned long long int e=n;
		unsigned long long int mid;

		float res=-1;
		while(s<=e){
			mid=s+e+1 >> 1;

			if(pow(mid,k)<=n){
				res=mid;
				s=mid+1;
			}
			else{
				e=mid-1;
			}̦
		}

		float dec=0.1;
		int precision;
		cin >> precision;

		for(int i=0;i<precision;i++){
			while(pow(res,k)<=n){
				res+=dec;
			}
			res-=dec;
			dec/=10;
		}

		cout<<res<<endl;
	}
	return 0;
}