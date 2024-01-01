#include <bits/stdc++.h>
using namespace std;

static int n1, n2;

int bit_needed1(){
    int temp = n1 ^ n2, count = 0;
    while (temp){
        if (temp & 1){
            count++;            
        }
        temp = temp >> 1;
    }
    return count;
}

int bit_needed2(){    
    int temp = n1 ^ n2;
    int count=0;
    
    while(temp){
        temp = temp&(temp-1);
        count++;
    }
    return count;
}
int main(){
    cin >> n1 >> n2;
    //approach1
    cout << bit_needed1()<<endl; 
    
    //approach2
    cout << bit_needed2();

    return 0;
}