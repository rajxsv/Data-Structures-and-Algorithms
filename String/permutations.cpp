#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

const int N = 0;

void permute(char * in , int i ,set<string> &res){
	
	if(in[i] == '\0'){
		res.insert(in);
		return;
	}

	for(int j =i;in[j]!='\0';j++){
		swap(in[i],in[j]);
		permute(in,i+1,res);
				
		// backtracking step
		swap(in[i],in[j]);
	}
}

int main(){
	
	char s[100];
	cin >> s;

	set<string> res;
	permute(s,0,res);

	for(auto i:res){
		cout << i << endl;
	}

	return 0;
}