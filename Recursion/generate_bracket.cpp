#include <iostream>
using namespace std;

const int N = 0;

void bracket(char *out,int n,int i,int open,int close){
	// base cases
	if(i==2*n){
		out[i]='\0';
		cout << out<<endl;
		return;
	}

	// rec case
	if(close<open){
		out[i]=')';
		bracket(out,n,i+1,open,close+1);
	}
	
	if(open<n){
		out[i]='(';
		bracket(out,n,i+1,open+1,close);
	}
	return;
	
}
int main(){
	int n;
	cin >> n;

	char out[10000];

	bracket(out,n,0,0,0);

	return 0;
}