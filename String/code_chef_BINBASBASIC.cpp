#include<iostream>
#include<string>
using namespace std;
int from_ends(int n , int k , int bn, int count1, string nb1){
    
    for(int i = 0,j = n-1 ; i<=j ; i++,j--){
       if(nb1.at(i)!=nb1.at(j)){
           nb1.at(i)=nb1.at(j);
           count1 += 1;
           
       }
    }
    return count1;
}

int from_mid(int n , int k , int bn, int count2, string nb1){
    
    for(int i = n/2 , j = n/2 ; i >= 0 , j <= n - 1 ; i--,j++ ){
         if(nb1.at(i)!=nb1.at(j)){
             nb1.at(i)=nb1.at(j);
             count2+=1;
             
         }
    }
    return count2;
}



int main() {
	int t,n,k,bn,count1=0,count2=0;
    cin >> t;
    if(t>=1 and t<=1000){
       for(int i = 1 ; i <= t ; i++){
           cin >> n >> k >> bn;
           string nb1 = to_string(bn);
           from_ends(n,k,bn,count1,nb1);
           from_mid(n,k,bn,count2,nb1);
           if(count1==k || count2 == k){
               cout << "YES"<<endl;
           }
           else{
               cout<<"NO";
           }
               
           
       }
    }
	return 0;
}
