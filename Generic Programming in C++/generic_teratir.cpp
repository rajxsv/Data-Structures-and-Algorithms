#include <iostream>
using namespace std;

// this template T is helping us to recieve 
template<typename T>
void search(T *start,T* end,T key){
	for(T* i = start ; i!=end ;i++){
			// cout << *i << " ";
		if((*i) == key){
			cout << (i-start)<<" ";
		}
	}
	return;
}
template<typename T>
void search2(T *start,T* end,T key){
	for(T* i = start ; i!=end ;i++){
			// cout << *i << " ";
		if((*i) == key){
			cout << (i-start)<<" ";
		}
	}
	return;
}


int main(){
	// int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	char arr[10] = {'a','b','c','d','e','f','g','h','i','j'};

	int n = 10;

	char key = 'g';
	search(arr,arr+n,key);
	search2(arr,arr+n,key);
	return 0;
}