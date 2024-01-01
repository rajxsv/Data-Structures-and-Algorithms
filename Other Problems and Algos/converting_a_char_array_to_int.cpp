#include<bits/stdc++.h>
using namespace std;

int converttoint(char a[],int n){
    int i = 0;
    int num = 0;
    while (i != n-1)
    {
        num =  a[i]+0 + (num * 10);
        i++;
        
    }
    return num;
}

int main() {

	int n1;
	cin >> n1;
	char num1 [n1];
	for(int i = 0 ; i < n1 ; i++)
	{
		cin >> num1[i];
	}

	int n2;
    cin >> n2;
	char num2[n2];
		for(int i = 0 ; i < n1 ; i++)
	{
		cin >> num2[i];
	}

	int x = converttoint(num1,n1);

    cout << x << endl;
	
	int y = converttoint(num2,n2);

	cout << y + x;
	return 0;
}