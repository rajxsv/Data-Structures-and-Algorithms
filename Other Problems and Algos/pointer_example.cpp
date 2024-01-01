#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;
    int *p = &n;
    int x = 10;
    int* xptr = &x;
    xptr = p;
    cout << n << endl << p << endl << x << endl << xptr ; 

    return 0;
}