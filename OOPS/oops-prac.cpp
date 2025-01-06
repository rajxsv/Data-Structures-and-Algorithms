#include <bits/stdc++.h> 

using namespace std;

// Why Is A's Constructor Called Only Once?
// When virtual inheritance is used:
// The most derived class (D in this case) is responsible for constructing the shared instance of the virtually inherited base class (A).
// Even though both B and C virtually inherit from A, they do not construct A themselves. Instead, they defer the responsibility to the most derived class.

class A {
public:
    A() {
        cout << "This is A with default constructor" << endl;
    }

    A(int x) {
        cout << "This is A with " << x << endl;
    }

    void fn () {
        cout << "Hello A !" << endl;
    }
};

class B : virtual public A {
public:
    B() {
        cout << "This is B with default cons " << endl;
    }

    B(int x) {
        cout << "This is B with " << x << endl;
    }

    // void fn () {
    //     cout << "Hello B !" << endl;
    // }
};

class C : virtual public A {
public: 
    C() {
        cout << "This is C with default cons " << endl;
    }

    C(int x) {
        cout << "This is C with " << x << endl;
    }

    // void fn () {
    //     cout << "Hello C !" << endl;
    // }
};

class D : public C, public B { // if i dont put public here then i cant call fn() of B from d's reference
public:
    D(int x) : B(x), C(x) {
        cout << "This is D with " << x << endl;
    }

    // int fn() {
    //     cout << "This is new fn from D" << endl;
    // }
};

int main () {
    // B* b = new B();
    // b->fn();
    D d = D(20);
    d.A::fn();
}