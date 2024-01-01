#include<bits/stdc++.h>
using namespace std;

// First we take xor of all numbers now this contains the xor contains the 2 non repeating numbers 
// now this xor contains both of the numbers that are unique 
// finding the i th bit that is set we can observe the fact of xor that this will be set in only one of the 
// numbers so we find this bit and store all numbers that has set bit at that position
// now this array contains all numbers that occurs 2 time and also bigger of the number that
// that occurs one time , taking xor of this array we get one of the uniqure numbers and 
// and we can get the other unique number by simply taking xor of this number with the first xor

pair <int,int> find(vector<int> &v , int n){
	int myxor = v[0];
	for (int i = 1; i < n; ++i){
		myxor ^= v[i];
	}
	
	int index = -1,i = 0;

	//finding where is the first set bit
	for(int i = 0; i <= 64; ++i)S{

		if(myxor&1)
		{
			index = i;
			break;
		} 	
		myxor = myxor >> 1;
	}

	//finding which elements have set bit at that pos
	int mask = 1 << index;

	vector <int> set_list(n);
	int j = 0;

	for (int i = 0; i < n; ++i){
		if (v[i] & mask){
			set_list[j++] = v[i];
		}
	}
	int myxor2 = 0;

	for (int i = 0; i < j; ++i){
		myxor2 ^= set_list[i];
	}
	int num1 = myxor2;	
	int num2 = myxor^myxor2;
	pair <int,int> res(make_pair(num2,num1));

	return res;
}

int main(){	
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}

	pair <int,int> p ;
	p = find(v,n);
	 
	cout << p.first <<" "<<p.second;

	return 0;
}