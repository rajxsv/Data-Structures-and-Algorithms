#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

void dictionary(char *in,int i,set<string> &res){
	if(in[i]=='\0'){
		string temp(in);
		res.insert(temp);
		return;
	}

	// rec case
	for(int j=i;in[j]!='\0';j++){
		swap(in[i],in[j]);
		dictionary(in,i+1,res);

		// backtracking
		swap(in[i],in[j]);
	}

	return;
}

int main(){

	char in[100];
	cin >> in;
	set<string> v;

	dictionary(in,0,v);

	string p(in);
	for(auto i:v){
		if(i>p){
			cout << i << endl;
		}
	}

	return 0;
}