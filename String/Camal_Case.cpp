#include <iostream>
using namespace std;

int main(){

	string s;
	cin >> s;

	int i = 0;

	while(i<(s.length()-1)){
		if(s[i]>='A' && s[i]<='Z' && s[i+1]>='A' && s[i+1]<='Z'){
			cout<<s[i++]<<endl;
		}
		else{

			cout<<s[i++];
			while(s[i]<='z' && s[i]>='a'){
				cout<<s[i];
				i++;
			}
			cout<<endl;	
		}
	}
	if(i<s.length()){
			if(s[i]>='A' && s[i]<='Z' && s[i+1]>='A' && s[i+1]<='Z'){
				cout<<s[i++]<<endl;
			}
			else{
				cout<<s[i];
			}
	}
	return 0;
}