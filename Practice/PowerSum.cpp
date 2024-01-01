#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
void fun(int n,int x , int i , int* cnt,int* sum ){

	// base case
	if((*sum)>n){
		return;
	}
	if((*sum)==n){
		(*cnt)++;
		return;
	}
	for(int j=i;j<sqrt(n);j++){
		(*sum)+=pow(j,x);
	}
	return;
}
	int main(){

	int n,x;
	cin >> n >> x;
	int ans=0;
	int sum=0;
	if(fun(n,x,1,&ans,&sum)){
		cout<<ans;
	}
	else{
		cout<<"NO";
	}

	return 0;
}