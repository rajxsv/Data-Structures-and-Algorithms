#include <iostream>
using namespace std;

const int N = 0;

void tower(int n,char source , char helper , char destination)
{
	// base case
	// if not disk is left
	if(n==0)return;

	// rec case
	// first going to the 1st disk, printing top to bottom
	tower(n-1,source,destination,helper);
	
	cout << "Moving ring "<<n<<" from "<<source<<" to "<<destination<<endl;

	tower(n-1,helper,source,destination);
}

int main()
{
	int n;
	cin >> n;

	tower(n,'A','B','C');

	return 0;
}