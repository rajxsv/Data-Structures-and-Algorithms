#include <bits/stdc++.h>
using namespace std;

/* Finding a bit: Find the Kth bit in binary representation of N.

Setting a bit: If Kth bit is 0, then set it to 1. Otherwise, leave it unchanged.

Clearing a bit: If Kth bit is 1, then clear it to 0. Otherwise, leave it unchanged.

Toggling a bit: If Kth bit is 1, then change it to 0 and vice-versa.

Modifying a bit: Replace the Kth bit with a given bit.
 */
int find_bit(int n, int k)
{
}
int toggle_bit(int n, int k)
{
    return (n ^ (1 << k));
}
int set_bit(int n, int k)
{
    return (n | (1 << k));
}
int clear_bit(int n, int k)
{
    return (n & ~(1 << k));
}
int modify_bit(int n, int k, int p)
{
    return (n | (p << k));
}
//
int main()
{
    cout << find_bit(5, 0) << endl;
    cout << toggle_bit(5, 0) << endl;
    cout << set_bit(5, 0) << endl;
    cout << clear_bit(5, 0) << endl;
    cout << modify_bit(5, 1, 1) << endl;
    
    \// SOME IMPORTANT THINGS

    // fidning xor between 1 to n

    // (n+i)=(n^i)+2*(n&i)
    return 0;
}
