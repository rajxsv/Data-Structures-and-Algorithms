#include<iostream>
#include <vector>
#include <unordered_map>
#include<string>
#include<algorithm>
using namespace std;

long long convert(string s){
	return ((s[0]-'0')*10 + s[1] - '0')*60 + (s[3]-'0')*10 + (s[4]-'0'); 
}


string converted(long long time){
	int day = (time/(60*24));
	time = time%(60*24);
	int hour = time/60;
	int min = time%60;
	return to_string(hour) + ":" + to_string(min);
}

int main(){
	vector<long long> times(4);
	for(int i=0; i<4; i++){
		string s;
		cin >> s;
		times[i] = convert(s);
	}
	vector<long long> chirps1;
	
	for(int i=0;i<=24*60;i++){
		chirps1.push_back(times[0] + times[2]*i);
	}

	for(int i=0;i<=24*60;i++){
		long long curr = times[1] + times[3]*i;
		if(binary_search(chirps1.begin(),chirps1.end(),curr)){
			cout<<converted(curr);
			return 0;
		}
	}
 	cout<<"NOT\n";

	return 0;
}