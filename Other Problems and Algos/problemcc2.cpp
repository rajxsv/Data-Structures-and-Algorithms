
#include <iostream>
using namespace std;
int fun(int n){
	int sum=0,d=5;
	while((n/d)>0){
		sum = sum + (n/d);
		d*=5;

	}
	return sum;
}

int main(){
	int n;
	cin >> n;
    cout << fun(n);
	return 0;
}
   
	             