#include<iostream>
using namespace std;
int main(){
    int n,sum;
    cin >> n;
    int a[1000] ={0} ;
    for(int i = 0 ; i < n ; i++ ){
    cin >> a[i];
    }  
    for(int i = 0 ; i < n ; i++ ){
        for(int j = i ; j< n ; j++){
            for(int k = i ; k <= j ; k++){
                cout << a[k]<< ",";
            }
            
            cout<<endl;
        }
    }
    return 0;
} 
