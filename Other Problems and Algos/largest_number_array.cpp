#include<bits/stdc++.h>
using namespace std;
int main() {

	int n1,n2;

	cin >> n1;
	vector <int> v1(n1);
	
	for(int i = 0 ; i < n1 ; i++){
		cin >> v1[i];
	}

	cin >> n2;
	vector <int> v2(n2);
	
	for(int i = 0 ; i < n2 ; i++){
		cin >> v2[i];
	}

	int i=n1-1,j=n2-1,carry=0;
	vector<int> ans;

	while(i>=0 || j>= 0 || carry){
		int sum = 0;
		if(i>=0)
		{
			sum+=v1[i--];
	
		}
		if(j>=0)
		{
			sum+=v2[j--];
			
		}
		sum += carry;
		carry = sum/10;

		ans.push_back(sum%10);

	}
		reverse(ans.begin(),ans.end());

		for(auto i : ans)cout << i<<", ";
		
		cout << "END" << endl;

	return 0;
}