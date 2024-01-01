#include<iostream>
using namespace std;
int main(){
    unsigned long long int a[100][100]={0};
    int m ;
    int n ;
    int key;
    int val = 1;
    cin >> m >> n >>key;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            a[i][j]=val;
            val +=1; 
        }
    }
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j < n ; j++){
          cout<<a[i][j]<<" ";
        }
        cout<<endl;
        
    }
    int row = 0 , col = 0;
    for(int i = 0 ; i<=m-1 ; i++){
      for(int j = 0 ; j <= n-1 ; j++){
        if(key > a[i][j]){
          row++;
        }
        else if(key < a[i][j]){
          col++;
        }
        else if(key == a[i][j]){
          cout<<key<<" is present at "<< row << " , "<<col;
          break;
        }
        else {
          cout << "key is not present";
        }
      }
    }
 
    return 0;
}