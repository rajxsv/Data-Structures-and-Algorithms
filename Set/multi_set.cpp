#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main(){


	multiset <int> m;

	int n;
	cin>>n;

	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		m.insert(x);
	}

	for(auto i:m){
		cout<<i<<",";
	}

	cout<<endl;

	 multiset<int, greater<int> > gquiz1;
 
    gquiz1.insert(40);
    gquiz1.insert(30);
    gquiz1.insert(60);
    gquiz1.insert(20);
    gquiz1.insert(50);
    gquiz1.insert(50);
    gquiz1.insert(10);

    multiset<int, greater<int> >::iterator itr;
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;

    cout<< *m.lower_bound(3)<<endl;
    cout<<*m.upper_bound(*m.find(3))<<endl;

    // remember lower_bound returs pointer and also s.find but lower bound parameters are int values!


    int arr[] = {1,1,1,2,2,6,6,6,7,7,8,9,123,123,32};
    n=sizeof(arr)/sizeof(arr[0]);
    multiset<int> m2(arr,arr+n);

    for(auto i:m2){
    	cout<<i<<",";
    }
    cout<<endl;

	return 0;
}