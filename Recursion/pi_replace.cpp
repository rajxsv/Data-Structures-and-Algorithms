#include <iostream>
using namespace std;

const int N = 0;

void replace(char *ch , int i)
{
	// base case
	if(ch[i]=='\0' || ch[i+1]=='\0')
	{
		return;
	}

	// rec case
	if(ch[i]=='p' && ch[i+1]=='i')
	{
		// int n = sizeof(ch)/sizeof(char);

		int j = 0;

		while(ch[j]!='\0')j++;

		while(j >= (i+2))
		{
			ch[j+2]=ch[j];
			j--;
		}

		ch[i] = '3';
		ch[i+1] = '.';
		ch[i+2] = '1';
		ch[i+3] = '4';
		i = i + 3;
	}	
	replace(ch,i+1);
}

int main()
{
	int t;
	cin >> t;
	cin.get();
	while(t--)
	{
		char ch[10000];

		cin.getline(ch,1000,'\n');
		replace(ch,0);

		for(int i = 0 ; ch[i]!='\0' ; i++)
		{
			cout << ch[i];
		}
		cout << endl;
		
	}
	return 0;
}