#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

bool myoperator(char ch){
	if(ch=='+' ||   ch=='-' || ch=='*' || ch=='/'){
		return true;
	}

	return false;
}

int main(){

	int t;
	cin >> t;

	while(t--){
		stack <int> st;

	string s;
	cin>>s;
	bool ans = true;

	for(int i=0;i<s.length();i++){

		if(myoperator(s[i])){
			st.push(s[i]);
		}
		else if(s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			if(st.top()=='('){
				ans=false;
				break;
			}
			while(myoperator(st.top())){
				st.pop();
			}

			st.pop();
		}
	}

	if(ans){
		cout<<"Not Duplicate"<<endl;
	}
	else{
		cout<<"Duplicate"<<endl;
	}
	}
	return 0;
}