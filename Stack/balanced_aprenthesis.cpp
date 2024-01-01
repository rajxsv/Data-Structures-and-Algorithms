#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	string s;
	cin >> s;
	int n=s.length();
	bool ans = true;;

	stack<int> st;
	// int i=0;
	for(int i=0;i<n;i++){
		// char temp=s[i++];
		switch(s[i]){
			case '(':
				st.push(s[i]);
				break;

			case '[':
				st.push(s[i]);
				break;

			case '{':
				st.push(s[i]);
				break;
			
			case ')':
				if(st.top()=='(')st.pop();
				else ans = false;
				break;

			case ']':
				if(st.top()=='[')st.pop();
				else ans = false;
				break;
			case '}':
				if(st.top()=='{')st.pop();
				else ans = false;
				break;
		}
	}
	if(st.empty() && ans){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}