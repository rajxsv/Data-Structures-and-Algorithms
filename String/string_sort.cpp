#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mycmp(string a,string b){
	if(a[0]==b[0]){

		int i = 0;
		while(i<a.length() && i<b.length() && a[i]==b[i]){
			i++;
		}
		if(i==min(a.size(),b.size())){

			return b.size()<a.size();
		}
	}

	return a<b;
}
void sort_game(vector<string> &v){
	sort(v.begin(),v.end(),mycmp);
}

int main(){

	int n;
	cin >> n;
	vector<string> v(n);

	for(auto &i:v){
		cin >> i;
	}

	sort_game(v);
	for(auto i:v){
		cout<<i<<endl;
	}
	return 0;
}