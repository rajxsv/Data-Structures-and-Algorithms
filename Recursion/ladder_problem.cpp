#include <iostream>
using namespace std;
// given n ,the number of stairs we need to find the ways to climb stars
// if one can makem jumps of 1,2,3 only.
int climbStairs(int n) {
        
       // base case
	// for zero 1 case as if we are standing on it there is only one way to reach it
        if(n==1 || n==0)
        {
            return 1;
        }
        if(n<0)
        {
            return 0;
        }
        
        // rec case
        return climbStairs(n-1) + climbStairs(n-2);
    }

const int N = 0;

int main()
{
	int n ;
	cin >> n;

	cout << climbStairs(n);


	return 0;
}