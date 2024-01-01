#include <iostream>
#include <set>
using namespace std;

void print(set<string> &res,string s){
	for(auto i:res){
		if(i<s){
			cout << i << endl;
		}
	}
}

void dictionary(string &s , int i , set<string> &res){
	if(i==s.length()){
		res.insert(s);
		return;
	}

	// rec case
	for(int j=i;j<s.length();j++){
		swap(s[i],s[j]);
		dictionary(s,i+1,res);

		// backtracking
		swap(s[i],s[j]);
	}
	return;
}

int main(){

	string s;
	cin >> s;
	set<string> res;

	dictionary(s,0,res);
	print(res,s);

	return 0;;
}