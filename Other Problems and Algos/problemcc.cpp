#include <iostream>
using namespace std;

int main(){
	// your code goes here
	int t;
	int n;
	cin >> t;
	for(int i = 1 ; i<= t ; i++){
	    cin >> n;
	    int ans = 1;
	    if(n==0){
	        ans = 0;
	    }
	    while(n>0){
	        ans = ans * n ;
	        n = n - 1;
	    }
	    cout << ans << endl;
	}
	return 0;
}
