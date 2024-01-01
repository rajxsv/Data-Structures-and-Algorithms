#include<iostream>
#include<forward_list>
#include<list>
#include<algorithm>
using namespace std;
int main(){
	list<int> f1;

	f1.push_back(1);
	f1.push_back(2);
	f1.push_back(3);
	f1.push_back(4);
	f1.push_back(5);
	f1.push_back(6);
	f1.push_back(7);
	f1.push_back(8);

	for(auto &i : f1){
		cout<<i<<" ";
	}

	return 0;
}