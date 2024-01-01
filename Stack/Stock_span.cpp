#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;

int main(){

	stack <int> s;
	int n;
	cin>>n;
	
	vector<int> v(n);
	vector<int> res(n);

	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	s.push(0);
	res[0]=1;
	
	for(int i=1;i<n;i++){
		while(!s.empty() && v[i]>=v[s.top()]){
			s.pop();
		}
		//now if stack is empty then the stock span is i+1 else it is i-(topMost Element)
		//we are pushing indexes to tackle from the duplicate problem
		res[i]=(s.empty()? (i+1) : i-s.top());	
		s.push(i);
	}
	
	for(auto i:res){
		cout<<i<<" ";
	}
	cout<<"END";
	return 0;
}