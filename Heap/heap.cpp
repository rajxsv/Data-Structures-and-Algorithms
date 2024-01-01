#include <iostream>
#include <vector>
using namespace std;

// template<typename U,typename V,typename W>
class Heap{
private:
	vector<int> v;
	bool minH;

	bool cmp(int a,int b){
		if(minH)
			return a>b;
		else
			return a<b;
	}
	void heapify(int i){
		int left = 2*i;
		int right = (2*i) + 1;

		int minIdx = i;

		if(left<v.size() && cmp(v[i],v[left])){
			minIdx = left;
		}
		
		if(right<v.size() && cmp(v[minIdx],v[right])){
			minIdx = right;
		}

		if(i!=minIdx){
			swap(v[minIdx],v[i]);
			heapify(minIdx);
		}
		// ! else it returns !
	}

public:
	Heap(bool mH=true){
		//Block 0th position
		v.push_back(-1);
		minH = mH;
	}
	void push(int d){
		
		v.push_back(d);
		int minIdx = v.size() -1;

		while(minIdx>1){
			int parent = minIdx/2;
			
			if(cmp(v[parent],v[minIdx])){  //send index leftWard if it is minHeap otherwise rightward
				swap(v[parent],v[minIdx]);
				minIdx = parent;
			}else{
				break; //it is at its correct position
			}
		}
	}

	void pop(){
		//Swap first and the last element
		int last = v.size()-1;
		swap(v[1],v[last]);  
		//remove (the first) now last element 
		v.pop_back();
		// heapify the first element to correct place
		heapify(1);
	}

	bool empty(){
		return v.size()==1;
	}
	int top(){
		return v[1];
	}
};

int main(){

	Heap h(false);
	// Heap h(true);
	
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		push(no);
	}

	cout<<h.top()<<endl;
	h.pop();
	h.pop();
	h.pop();
	cout<<h.top()<<endl;
}