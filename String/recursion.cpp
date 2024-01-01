#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 0;

void subsets(const char* in , char* out , int i , int j)
{
	// base case

	if(in[i]=='\0')
	{	
		out[j] = '\0';	
		cout << out << endl;
		return; 
	}

	// either we take first 2 elements 
	// or both

	int digit = in[i] - '0';
	char ch = digit + 'A' - 1;
	out[j] = ch;

	subsets(in,out,i+1,j+1);

	if(in[i+1]!='\0')
	{
		int no;
		int digit2 = in[i+1]-'0';
		no=digit*10 + digit2;

		if(no<=26)
		{
			char ch2 = no + 'A' - 1;
			out[j]=ch2;

			subsets(in,out,i+2,j+1);
		}	
	}
	
	return;


}
int main()
{
	string s;
	cin >> s;

	char out [s.size()];
	

	subsets(s.c_str(),out,0,0);
	return 0;
}