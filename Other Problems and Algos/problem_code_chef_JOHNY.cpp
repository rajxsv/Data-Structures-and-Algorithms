#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
	int store;
	int n,k;
	cin >> t;
	for(int q = 1 ; q <= t ; q++){
	    cin >> n ;
		int a[100]={0};
        
	    for(int i = 0 ; i < n ; i++){
	        cin >> a[i];
		}
		cin >> k;
		if(k<=n){
			for(int i = 0 ; i < n ; i++){
	          if(a[i]==a[k-1]){
                 store = a[i];
				 break;
			  } 
			  
	    	}
            sort(a,a+n);
		
	     	int i = 0;
	        for(i = 0 ; i < n ; i++){
	            if(a[i]==store){
			    	break;
		    	}
 	     	}
     		cout<<i+1<<endl;
		}
	    
    }    
	return 0;
}
     
	     
	    
	   
		

        