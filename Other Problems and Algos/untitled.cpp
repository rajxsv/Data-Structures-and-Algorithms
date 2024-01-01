#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n,c,max_sum=INT_MIN;
    cin >> n;
    int a[1000] ={0} ;
    for(int i = 0 ; i < n ; i++ ){
    cin >> a[i];
    }  
    for(int i = 0 ; i < n ; i++ ){
        for(int j = i ; j< n ; j++){
            int sum=0;
            for(int k = i ; k <= j ; k++){
                sum+=a[k];
            }
            if(sum>max_sum)
           
            
        }
    }
    cout << "max sum is " << max_sum<<endl<<"And the corresponding array is "<<endl;
    
    return 0;
} 
