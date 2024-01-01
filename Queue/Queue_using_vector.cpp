#include <iostream>
#include <vector>
using namespace std;

class queue{
private:
	vector<int> v;

public:
	void push(int data){
		v.push_back(data);
		return;
	}
	void pop(){
		//delete v[0]
		v.erase(v.begin()+0);
	}
	int back(){
		return v[v.size()-1];
	}
	int front(){
		return v[0];
	}
	bool empty(){
		if(v.size()==0){
			return true;
		}
		return false;
	}
};

void print(queue q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
}
int main(){
	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	print(q);


	return 0;
}