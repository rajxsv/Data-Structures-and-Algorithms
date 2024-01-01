#include<bits/stdc++.h>
using namespace std;
int clearbits(int n , int i , int j)
{
    int ones = ~(0);
    int a = -(0) << (j+1);   //something like 11110000000
    int b = pow(2,i) - 1;   //00001111  where i is the number of 1 u want
    int mask = (a | b);
    return (n & mask);
}

int insertMinN(int n , int m , int i , int j)
{
    int n_ = clearbits(n,i,j);
    return (n_ | m<<i);
}

int main()
{
    int n = 15;
    int m = 2;

    int i = 1 , j = 3;

    cout << insertMinN(n,m,i,j);
    
    return 0;
}