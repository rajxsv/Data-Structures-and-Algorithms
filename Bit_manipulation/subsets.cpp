#include<bits/stdc++.h>
using namespace std;

vector <int> print(vector <int> s , int i){	
	int j = 0;
	vector <int> sub;
	
	while(i>0){
		if(i & 1){
			sub.push_back(s[j]);
		}
		j++;
		i = i >> 1;
	}
	
	return sub;
}

vector<vector<int>> createsubsets(vector<int>& s){
    
    vector <vector<int>> res;
	
	for(int i = 0 ; i <= ((1 << s.size()) - 1) ; i++){
		res.push_back(print(s,i));
	}
    
	return res;
}

int main(){
	int n;
	cin >>n;
	
	vector<int> s(n);
	// s.resize(n);
	for(auto &i : s){
		cin >> i;
	}

	// vector <int> s = {1,2,3};
	
	vector <vector<int>> print = createsubsets(s);

	for(int i = 0 ; i < print.size() ; i++){
		for (int j = 0; j < print[i].size(); j++){
			cout << print[i][j]<<" ";
			/* code */
		}
		cout << endl;
	}
	return 0;
}

