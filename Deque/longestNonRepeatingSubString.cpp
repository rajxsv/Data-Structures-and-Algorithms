#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// ! Problem based on sliding window problem

int main(){

	char a[] = "ancdefcghijkzyxyz";
	// char a[] = "ancdef";
	// string a = "abcdefg";

	int n = a.size();
	int current_len = 1;
	int max_len = 1;

	int visited[256];
	for(int i=0;i<n;i++){
		visited[i] = -1;
		// all not visisted
	}

	visited[a[0]] = 0; //index of first char
	"abccddee"
	 0123
	for(int i=1;i<n;i++){
		int last_occ = visited[a[i]];

		//expand if it comes first time or it goes out of window
		if(last_occ==-1 || current_len>last_occ){
			current_len++;
		}
		else{
			//expand + contract
			//if greater pdate
			current_len = i-last_occ;
		}
		max_len=max(max_len,current_len);
		visited[a[i]]=i;
	}

	cout<<max_len<<endl;

	return 0;
}