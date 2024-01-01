#include<iostream>
#include<algorithm>
using namespace std;
void transpose( int a[][100], int m , int n){
    cout<<"m here"<<endl;
    for(int j= 0 ; j<n ; j++){
        for(int i = 0 ; i<m ; i++){
            if(i>j){
                swap(a[i][j],a[j][i]);
            }
        }
    }
    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j<n ; j++){
            cout << a[i][j] << " ";
        }
        cout<<endl;
    }
}
void reverse( int a[][100] , int m , int n){
    int i = 0;
    int j = n-1;
    int row = 0;
    for(row=0 ; row < m ; row++){
        i = 0;
        j=n-1;
       while(i<j){
        swap(a[row][i],a[row][j]);
        i++;
        j--;
        }
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j<n ; j++){
            cout << a[i][j] << " ";
        }
        cout<<endl;
    }
    transpose(a,m,n);
    
}

int main(){
    int a[100][100]={0},m,n;
    cin >> m >> n;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j<n ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j<n ; j++){
            cout << a[i][j] << " ";
        }
        cout<<endl;
    }
    reverse(a,m,n);
   
    return 0;
}