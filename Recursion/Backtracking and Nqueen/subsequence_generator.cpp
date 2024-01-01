#include <iostream>
#include <string.h>
using namespace std;

const int N = 3;	

void generate_seq(char *in ,char *out,int i , int j,int *c)
{
	if(in[i]=='\0')
	{
		// count(1);	
		(*c)++;
		out[j]='\0';
		cout << out <<endl;
		return;
	}

	// rec case
	// call including i th index
	out[j] = in[i];
	generate_seq(in,out,i+1,j+1,c);

	// call without that index but go the next 
	generate_seq(in,out,i+1,j,c);


	// order of above 2 calls can be changed acc to the question demand
}

int main()
{
	// string in;
	// cin >> in;

	// string out ;

	char in[100];
	cin >> in;

	char out[100];

	int count=0;

	generate_seq(in,out,0,0,&count);

	cout << count;
	// cout << j ;

	return 0;
}