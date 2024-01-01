#include <iostream>
#include <string>

using namespace std;

void fun(string &s,int i){
	// base case
	if(i == s.length()){
		return;
	}

	// rec case
	if(s[i]==s[i+1]){
		cout << s[i];
		while(s[i] == s[i+1]){
			i++;
		}
	}
	else{
		cout << s[i];
	}

	fun(s,i+1);
}

int main(){
	string s;
	cin >> s;

	fun(s,0);

	return 0;
}