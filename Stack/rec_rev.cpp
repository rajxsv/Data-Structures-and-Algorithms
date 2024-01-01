#include <iostream>
#include <stack>
using namespace std;

void input(stack <int> &s){
	int n;
	cin >> n;

	int data;
	while(n--){
		cin>>data;
		s.push(data);
	}
}

void print(stack <int> s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}
void insert_at_bottom(stack<int> &s,int data){
	if(s.empty()){
		s.push(data);
		return;	
	}

	int temp=s.top();
	s.pop();

	insert_at_bottom(s,data);

	s.push(temp);
}

void rev_rec(stack<int> &s){
	if(s.empty()){
		return;
	}

	int data=s.top();
	s.pop();

	rev_rec(s);

	insert_at_bottom(s,data);
}

int main(){
	stack <int> s;
	input(s);

	rev_rec(s);
	print(s);
}