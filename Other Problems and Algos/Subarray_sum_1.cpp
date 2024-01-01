#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n,current_sum=0,max_sum=INT_MIN,left,right;
    cin >> n;
    
    int a[1000] ={0} ;
    
    for(int i = 0 ; i < n ; i++ ){
    cin >> a[i];
    }  
    
    for(int i = 0 ; i < n ; i++ ){
        for(int j = i ; j< n ; j++){
            current_sum = 0;
            for(int k = i ; k <= j ; k++){
                current_sum += a[k];
            }
            if(current_sum>max_sum){
                max_sum = current_sum;
                left = i;
                right = j; 
            }
            
        }
    }    
    cout << "max sum is " << max_sum<<endl<<"And the corresponding array is "<<endl;
    for(int w = left ; w<= right ; w++){
        cout <<a[w]<<",";
    }

    return 0;
} 
