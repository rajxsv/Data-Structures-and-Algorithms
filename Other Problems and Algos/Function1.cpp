#include<iostream>
using namespace std;
void printabcd (){
    int n=10;
    for(int i=1 ; i <=n ; i++){
        char alphabet = 'A';
        int col = n-i+1;
        for(int j = 1 ; j<=col ; j++){
            cout << alphabet ;
            alphabet += 1 ;
        }
        cout <<"\n";
    }

}
int main(){
    int n;
    cin >> n;
    printabcd();
    
    return 0;
}