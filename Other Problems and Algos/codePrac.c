#include <iostream>
using namespace std;


int main() {
    float a;
    cin>>a;
    int count=0;
    while(a!=0){
       a=a-(int)a;
       count++;
       a=a*10;
    }
    cout<<(int)a;
    
    
    return 0;
}
