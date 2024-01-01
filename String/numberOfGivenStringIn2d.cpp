#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> dx = {0,1,0,-1};
vector<int> dy = {1,0,-1,0};


void findWordAt(string &needle,vector<string> &input,int i,int j,int n,int m,int idx,int &ans){
	if(idx==needle.length()){
		ans++;
		return;
	}

	if(i>=n || j>=m){
		return; 
	}
	if(needle[idx]!=input[i][j]){
		return;
	}

	for(int xy=0;xy<4;xy++){

		if(i+dx[xy]<n && j+dy[xy]<m){
			findWordAt(needle,input,i+dx[xy],j+dy[xy],n,m,idx+1,ans);
		}
	}

	return;
}

void findNoOfTImes(string &needle , vector<string> &input,int &ans){
	int n = input.size();
	for(int i=0;i<n;i++){
		int m = input[i].length();
		for(int j=0;j<m;j++){
			findWordAt(needle,input,i,j,n,m,0,ans);
		}
	}
	// cout<,ans;
	return;
}

int main(){
	string needle = "MAGIC";
	vector<string> input = { 
					"BBABBM",
					"CBMBBA",
					"IBABBG",
					"GOZBBI",
					"ABBBBC",
					"MCIGAM" };

	int ans = 0;
	findNoOfTImes(needle,input,ans);
	cout<<ans<<endl;
	return 0;
}