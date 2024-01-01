#include <iostream>
#include <string.h>
using namespace std;

const int N = 0;
// We make subsets here as well byt the difference is we call eah element and include every digit
// and for each digit we call its every possible char
void keypad(const char* in,char* out,int i,int j,string table[])
{
	// base case
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout << out << endl;
		return;
	}
	
	int digit = in[i]-'0';
	// the following cndtn is only for in case you need to skip null of 0
	// but in this ques it is space so we dont skip it 
	// if(digit==0)
	// {
	// 	keypad(in,out,i+1,j,table);
	// }

	// making calls for each element of that digit 
	// else
	// {
		for (int k = 0; k < table[digit].size() ; ++k)
		{
			out[j]=table[digit][k];
			keypad(in,out,i+1,j+1,table);

		}
	// }
}

int main()
{
	string s;
	cin >> s;

	char out[s.size()];

	string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
	keypad(s.c_str(),out,0,0,table);

	return 0;
}