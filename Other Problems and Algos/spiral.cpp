#include<iostream>
using namespace std;

void spiral(int a [][100], int m , int n){
    int sr = 0;
    int er = m - 1;
    int sc = 0;
    int ec = n - 1;
  
    while(sr <= er){
        // row print
        for(int i = sc ; i <=ec ; i++){
            cout<<a[sr][i];
        }
        sr++;
        
        // col print
        for(int i = sr ; i<=er ; i++){
            cout<<a[i][ec];
        }
        ec--;
        
        // row print
        if(ec>sc){
            for(int i = ec ; i >= 0 ; i-- ){
               cout<<a[er][i];
            }
        }
        er--;
        
        // col print
        if(er>sr){
            for(int i = ec ; i>=sc ; i--){
               cout<<a[i][sc];
            }
        }
        sc++;
    }
}

int main(){
    int a[100][100]={0};
    int m,n;
    int val = 1;
    cin >> m >> n;
    for(int row = 0 ; row < m ; row++){
       for(int col = 0 ;  col < n ;  col++){
           a[row][col]=val;
           val+=1;
           cout << a[row][col] << " ";
       }
       cout<<endl;
    }
    spiral(a , m , n);
    return 0; 
}
    