#include <iostream>
#include <deque>
using namespace std;

#define ll long long

bool valid(deque<char> s){
	// string t1 = "101";
	// string t2 = "010";

	deque<char> t1 = {'1','0','1'};
	deque<char> t2 = {'0','1','0'};

	return (s==t1) || (s==t2);

}

int main(){

	deque<char> res;
	string s;
	int t;
	cin >> t;

	while(t--){
		cin>>s;
		ll n=s.length();
		deque<char> res;
		
		ll i=0;
		for(i=0;i<3;i++){
			res.push_back(s[i]);
		}

		if(valid(res)){
			cout<<"GOOD"<<endl;
		}
		else if(n<3){
			cout<<"BAD"<<endl;
		}
		else{
			while(i<n){
				res.pop_front();
				res.push_back(s[i++]);
				if(valid(res)){
					cout<<"GOOD"<<endl;
					break;
				}

			}

			if(i==n){
				if(valid(res)){
					cout<<"GOOD"<<endl;
				}
				else{
					cout<<"BAD"<<endl;
				}
			}
		}


	}
	return 0;
}