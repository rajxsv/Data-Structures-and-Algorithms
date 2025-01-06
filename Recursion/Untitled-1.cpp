#include <bits/stdc++.h> 

using namespace std;

class A {
public:
    A() {
        cout << "This is A with default cons " << endl;
    }

    A(int x) {
        cout << "This is A with " << x << endl;
    }
};

class B : A {
public:
    B() {
        cout << "This is B with default cons " << endl;
    }

    B(int x) {
        cout << "This is B with " << x << endl;
    }
};

class C : B {
public: 
    C() {
        cout << "This is C with default cons " << endl;
    }

    C(int x) {
        cout << "This is C with " << x << endl;
    }
};

class D : C, B {
public:
    D(int x) : B(x), C(x), A(x) {
        cout << "This is D with " << x << endl;
    }
};

int main () {
    D* d = new D(20);
}