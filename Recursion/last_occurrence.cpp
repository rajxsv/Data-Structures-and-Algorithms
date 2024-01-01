#include <iostream>
using namespace std;

const int N = 8;
int key = 7;

int last_occ(int arr[],int i,int ans)
{
	if(i==N)return ans;

	if(arr[i] == key)ans = i;

	return last_occ(arr,i+1,ans);
}

int Last_Occ(int arr[] ,int n)
{
	if(n==0)return -1;

	int i = Last_Occ(arr+1,n-1);
	
	if(i==(-1)){
		if(arr[0]==key)return 0;
		
		else return -1;
	}

	return i+1;
}

int main()
{
	int arr[N] = {2,6,3,7,7,7,9,15};
	
	cout << last_occ(arr,0,-1) << " Using Approach 1\n";

	cout << Last_Occ(arr,N)  << " Using Approach 2\n";

	return 0;
}