#include<iostream>
using namespace std;

int main(){

    float r;

    cin >> r;

    for(float i=-r; i<=r; i++){
        for(float j=-r; j<=r; j++){
            if((i*i) + (j*j) <= (r*r)){
                cout << '.' << " ";
            }else{
                cout << ' ' << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}