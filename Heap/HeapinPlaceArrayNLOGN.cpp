#include<iostream>
#include<vector>
using namespace std;
//make array to heap (in place) 

void buildHeap(vector<int> &v){
    for(int i=1;i<v.size();i++){
        int idx=i;
        int parent = i/2;

        while(idx> 1 && v[idx]>v[parent]){
            swap(v[idx],v[parent]);
            idx=parent;
            parent/=2;
        }
    }
}
template<typename T>
void print(vector<T> &v){
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){

    vector<int> v={-1,10,20,5,6,1,8,9,4,80,90};

    print(v);
    buildHeap(v);
    print(v);

    return 0;
}