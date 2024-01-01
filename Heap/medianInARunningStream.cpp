#include <iostream>
#include <queue>//for heap
#include <iomanip>

using namespace std;
// for odd middle most ele
// for even average of middle 2

/*
	sorting everytime would lead to N2logN
	everytime put ele at corect sorted pos
	
*/
int main(){

	priority_queue<float> leftHeap; //maxHeap
	priority_queue<float,vector<float>,greater<float>> rightHeap; //minHeap

	float d;
	cin>>d;

	float med = d;

	leftHeap.push(d);

	while(d!=-1){
		
		if(leftHeap.size()>rightHeap.size()){
			//migrating if needed happens from left to right
			if(d<med){
				rightHeap.push(leftHeap.top());
				leftHeap.pop();
				leftHeap.push(d);
			}else{
				rightHeap.push(d);
			}

			med=(leftHeap.top()+rightHeap.top())/2;

		}else if(leftHeap.size() == rightHeap.size()){
			if(d<med){
				leftHeap.push(d);
				med=leftHeap.top();
			}else{
				rightHeap.push(d);
				med=rightHeap.top();
			}
		}else{
			if(d>med){
				leftHeap.push(rightHeap.top());
				rightHeap.pop();
				rightHeap.push(d);
			}else{
				leftHeap.push(d);
			}
			med=(leftHeap.top()+rightHeap.top())/2;

		}

		cout<<"Median "<<setprecision(10)<<med<<endl;
		cin>>d;

	}

	return 0;
}