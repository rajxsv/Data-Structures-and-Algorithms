#include<iostream>
using namespace std;
void printabcd (int n){
    
    for(int i=1 ; i <=n ; i++){
        char alphabet = 'A';
        int col = n-i+1;
        for(int j = 1 ; j<=col ; j++){
            cout << alphabet ;
            alphabet = alphabet + 1 ;
            
        }
        cout <<endl;
    }

}
int main(){
    int n;
    cin >> n;
    printabcd(n);
    
    return 0;
}