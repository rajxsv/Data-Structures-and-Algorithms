#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	//problem is at spoj
	//we started with defining area and then we started finding it
	//we broke it into sub problem of finding length and breadth and then we found 
	//it using independently
	
	int t;
	int w,h,n;
	cin>>t;

	int x[40010],y[40010];


	while(t--){
		cin>>w>>h>>n;
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i];
		}

		sort(x,x+n);
		sort(y,y+n);

		//finding delta x and y we do -1 as in dx - 0 -1
		// starting to first tower
		int dx = x[0]-1;
		int dy = y[0]-1;
	
		for(int i=1;i<n;i++){
			dx = max(dx,x[i]-x[i-1]-1);
			dy = max(dy,y[i]-y[i-1]-1);
		}
		//ast tower to end 
		dx = max(dx,w-x[n-1]);
		dy = max(dy,h-y[n-1]);

		cout<<dx*dy<<endl;
	}

	return 0;
}