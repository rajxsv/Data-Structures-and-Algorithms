#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
int main(){

	bitset<10> bs;
	bitset<10> bs2(string("1111111000"));
	bitset<10> bs3(5);

	cout<<bs<<endl;
	cout<<bs2<<endl;
	cout<<bs3<<endl;

	cout<<bs2[0]<<" ";
	cout<<bs3[0]<<" ";
	cout<<bs[2]<<endl;
	
	cout<<bs2.count()<<endl;
	
	int x= bs2.size()-bs2.count();
	cout<<x<<endl;
	
	x=bs3.size() - bs2.count();
	cout<<x<<endl;

	cout<<bs2.any()<<endl;

	bs2.set();
	cout<<"bs2 is set now "<<bs2<<endl;

	cout<<bs2.none()<<endl;

	bs3=10000000;

	bs3.set(5,1);
	cout<<bs3<<endl;

	bitset<64> b(7);
	bitset<64> b0(-7);

	cout<<b<<endl<<b0<<endl;
	cout<<(50&-50);

	return 0;
}