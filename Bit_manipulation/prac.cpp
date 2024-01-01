#include <iostream>
#include <ctime>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE 
		clock_t tstart = clock();

	#endif
		int n;
		cin >> n;
		while(n--){
			cout<<"hm"<<endl;
		}
	#ifndef ONLINE_JUDGE 
		fprintf(stderr,"\nruntime: %.10fs",(float)((clock()-tstart)/CLOCKS_PER_SEC));

	#endif
}