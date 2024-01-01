#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int solve(vector<int> &v, int i, int leftSum, int rightSum, int len){
    if(i<0)return 0;
    
    
    // either i take or i dont
    int a = solve(v, i-1, 0, rightSum+leftSum, len);
    int b = 0;
    
    if(leftSum == rightSum){
        return max(len, a);
    }
    
    if(leftSum + v[i] <= rightSum){
        b = solve(v, i-1, leftSum + v[i], rightSum - v[i], len+1);
    }
    
    return max(a, b);
}

int evenSubStr(vector<int> &v){
    int n = v.size();
    int sum = 0;
    
    for(int i=0; i<n; i++){
        sum += v[i];
    }
    
    return solve(v, n-1, 0, sum, 0);
}


int main() {
    
    int t,n;
    cin >> t;
    
    while(t--){
    	cin>>n;
    	
    	vector<int> v(n);
        
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        cout << evenSubStr(v) << endl;
    }
    	
	return 0;
}