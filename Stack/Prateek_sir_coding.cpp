#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack <int> s;

	int n;
	cin>>n;
	int data;
	for(int i=0;i<n;i++){
		cin>>data;
		if(data==2){
			cin>>data;
			s.push(data);
		}
		else{
			if(s.empty()){
				cout<<"No Code"<<endl;
			}
			else{
				cout<<s.top()<<endl;
				s.pop();
			}
		}
	}

	return 0;
}