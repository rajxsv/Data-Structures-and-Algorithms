#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

bool primefactors(int n){
	vector <pair<int,int>> factors;
	int power;
	for (int i = 2; i*i <= n; ++i)
	{
		power = 0;
		if(n%i == 0)
		{
			while(n%i==0)
			{
				power++;
				n/=i;
			}

			factors.push_back(make_pair(i,power));
		}
	}
	if(n!=1)
	{
		factors.push_back(make_pair(n,1));
	}

	for(int i = 0 ; i < factors.size() ; i++)
	{	
		if(factors[i].first > 3){
			return false;
		}
		// cout << factors[i].first << "^" <<factors[i].second <<" ";	
	} 
	return true;

}

int ans = 0;
int dp[17][32];

int solve(int mask, unordered_map<int,int> &maskedPrimeFact, int cnt, int &size){
	// cout << cnt << " ";
	if(cnt == 0){
		return 1;
	}
	int ans = 0;

	if(dp[cnt][mask] != -1){
		return dp[cnt][mask];
	}

	for(int i=0;i<size;i++){
		if(mask&(1<<i)){
			continue;
		}
		int check = maskedPrimeFact[i];

		if((check&mask) == check){
			int mask2 = mask | (1<<i);
			ans += solve(mask2, maskedPrimeFact, cnt-1, size);
		}

	}
	return dp[cnt][mask] = ans;
}

string toBinary(int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}


int main(){
	vector<int> vec;
	unordered_map<int,int> maskedPrimeFact;
	maskedPrimeFact[1] = 0;
	// cout << 1 << " " << 0 << endl;

	for(int i=1; i<=70;i++){
		if(primefactors(i)){
			// cout << i << " " << endl;
			vec.push_back(i);
		}
	}

	for(int i=1;i<=16;i++){
		int mask = 0;
		for(int j=0;j<i;j++){
			if(vec[i]%vec[j] == 0){
				mask = mask | (1<<j);
			}
		}
		maskedPrimeFact[i] = mask;
		// cout << vec[i] << " " << toBinary(mask) << endl;
	}
	// cout << maskedPrimeFact.size() << " size "<< vec.size() << endl;
	int n;
	cin >> n;

	int cnt = 0;
	for(auto i:vec){
		if(i>n){
			break;
		}
		cnt++;
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, maskedPrimeFact, cnt, cnt) << endl;
	// cout << ans << endl ;
}