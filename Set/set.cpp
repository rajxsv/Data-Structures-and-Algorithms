#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;



int main(){

    set<int> v;
    
    int n;
    cin >> n;
    int x;      
    for (int i = 0; i < n; ++i){
        cin >> x;
        v.insert(x);
    }

    // way 1 to cout
    for(auto i:v){
        cout << i << " ";
    }

    cout << endl ;
    // way 2
    
    for(set<int>::iterator itr = v.begin();itr!=v.end();itr++){
        cout << *itr<< " ";
    }

    unordered_set<int> v2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v2.insert(x);
    }

    for(auto i:v2){
        cout<<i<<",";
    }

    return 0;
}

