#include <iostream>
using namespace std;

// O()

const int N = 0;
#define ll long long

void gen_subset(int i,int no,int* prime,int* ans)
{
	int temp= 1;
	int j = 0;
	int count=0;
	// int ans=0;

	while(i>0)
	{
		if(i&1)
		{
			temp *= prime[j];
			count++;
		}

		j++;
		i=i>>1;
	}

	if(count&1)	
	{
		*ans += no/temp;
	}
	else
	{
		*ans -= no/temp;
	}
}

void fun(int no , int prime[] ,int* ptr)
{

	for(int i = 1 ; i < (1<<8) ; i++)
	{
		gen_subset(i,no,prime,ptr);
	}

}

int main()
{
	int t;
	cin >> t;
	int prime[] = {2,3,5,7,11,13,17,19};

	while(t--)
	{
		int no;
		cin >> no;
		int ans = 0;
		fun(no,prime,&ans);
		cout << ans <<endl;
	}

	return 0;
}