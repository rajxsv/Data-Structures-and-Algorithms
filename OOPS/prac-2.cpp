#include <bits/stdc++.h>

using namespace std;

class Shape {
public:
    virtual void v() {
        cout << "This is v from Shape" << endl;
    } 
    // virtual void v() = 0;
    virtual void fn() {
        cout << "This is fn from Shape" << endl;
    }
};

class Rectangle : public Shape {
public:
    void v() override {
        cout << "This is v from Rectangle";
    }
    void fn() {
        cout << "This is fn from Rectangle" << endl;
    }
};

class Calculator {
public:
    Calculator() {
        cout << "This is Calculator" << endl;
    }

    void add(int a, int b, int c) {
        cout << a+b+c << endl;
    }

    void add(int a, int b) {
        cout << a+b << endl;
    }
};

int main() {
    Shape s = Shape();  
    // s.v();  // this fails if shape has atleast one pure virtual function 

    Shape* s2 = new Shape();

    Rectangle* r = new Rectangle();

    s2 = r;

    s2->Shape::fn();

    Calculator *c = new Calculator();
    
    return 0;
}