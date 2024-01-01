#include <iostream>
using namespace std;

class base {
public:
	int a;
};

class derived1 : public Base{
public:
	int b;
};


int main(){
	derived1 d1;
	d1.b = 10;
	d1.a = 20;

	cout << d1 << endl;
	return 0;
}