//chef_and_subsets
#include<iostream>
using namespace std;
int main(){
    int t , n , x , y,a[1000]={0},b[1000]={0},no;
    cin >> t;
    if((t > 1) && (t <= 10)){
        for(int w = 1 ; w<= t ; w++ ){
           cin >> n >> x >> y ;
           int c1 = 0 , c2 = 0;
           for(int i = 0 ; i < n ; i++ ){
               cin >> a[i];
            }
           for(int j = 0 ; j < n ; j++){
               cin >> b[j];
            }
           for(int k = 0 ; k < n ; k++){
               int d = 0;
               if(b[k]==a[k]+x){
                  c1 +=1;
                  d+=1;
                }
                else if(b[k]==a[k]+y){
                  c2+=1;
                  d+=1;
                }
                if(d==2){
                  c2 - 1;
                }
            }
            if((c1+c2)==n){
            cout<<"YES";

            }
            else{
            cout<<"NO";
            }
            cout << endl;
    }
        
    

    }




    return 0;
}