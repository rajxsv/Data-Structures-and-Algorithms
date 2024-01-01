#include<iostream>
#include<vector>
using namespace std;
//make array to heap (in place) 

void heapify(vector<int> &v,int i,int size){
		int left = 2*i;
		int right = (2*i) + 1;

		int minIdx = i;

		cout << "Heaping index "<<i << " with children " << v[left] <<" "<<v[right] << endl;

		if(left<size && v[minIdx]<v[left]){
			minIdx = left;
		}
		if(right<size && v[minIdx]<v[right]){
			minIdx = right;
		}

		if(i!=minIdx){
			cout << "swapped "<<v[minIdx]<<" , "<< v[i]<<endl;
			swap(v[minIdx],v[i]);
			heapify(v,minIdx,size);
		}
		// ! else it returns !
	}

void buildHeap(vector<int> &v){
    //to not take the leaf nodes as they are already fine,things alone are already heapified
    int n = v.size();
    for(int i=n/2;i>=1;i--){   // start from first non leaf node
        cout << "calling " << i << endl;
        heapify(v,i,n);
    }
}

void heapSortHelper(vector<int> &v){
	int n = v.size();

	while(n > 1){
		swap(v[1], v[n-1]);
		n--;
		heapify(v, 1, n);
	}
}

void heapSort(vector<int> &v){
	buildHeap(v);
	heapSortHelper(v);
}

template<typename T>
void print(vector<T> &v){
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){

    vector<int> v={-1,10,20,5,6,1,8,9,4,60,80};

    print(v);
    buildHeap(v);
    print(v);
    heapSort(v);
    print(v);

    return 0;
}