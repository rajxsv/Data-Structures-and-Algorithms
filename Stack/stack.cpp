#include <iostream>
#include <stack>

using namespace std;
void print(stack <int> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}
int main(){
	stack <int> s;
	for(int i=0;i<10;i++){
		s.push(i);
	}
	print(s);
	
}
