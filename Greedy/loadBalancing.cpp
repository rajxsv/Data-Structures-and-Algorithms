    #include <iostream>
    #include <climits>
    #include <algorithm>
    using namespace std;

    //for leading to the solution to this problem we thought from answer back to the problem

    int main(){
     
    	while(true){
    		int n;
    		cin>>n;
     
    		if(n==(-1)){
    			break;
    		}
            
    		int processors[n];
    		int load=0;

    		for(int i=0;i<n;i++){
    			cin>>processors[i];
    			load+=processors[i];
    		}
            
    		if(load%n){
    			cout<<-1<<endl;
    			continue;
    		}
     
    		load=load/n;//this is the load that should be in each part of the array
    		
    		int max_load=INT_MIN;
    		int ans;
    		int diff = 0;
     
    		for(int i=0;i<n;i++){
    			diff += (processors[i]-load);
    			ans = abs(diff);
    			max_load=max(ans,max_load);
    		}
     
    		cout<<max_load<<endl;
    	}
     
    	return 0;
    } 