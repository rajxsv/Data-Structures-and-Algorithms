#include<iostream>
#include<vector>
#include<array>

using namespace std;
int main()
{
    //ARRAY
    array<int , 5>{{2,34,54,3,2}};

 
    //vector
    vector <int> v = {2,4,5,6,7,8,9} ;
    
    for(auto i : v)cout << i <<" ";
    
    cout<<endl;

    string s = "rajpreet";

    for(char i : s)cout << i << " ";


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return false;
        if (n==1 )
        {
            return true;
        }
        if (isPowerOfTwo(n/2) && n%2 == 0)
        {
            return true;
        }
        else 
        {
        return false;
        }
    }
};
    return 0;
}

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return false;
        if (n==1 )
        {
            return true;
        }
        if (isPowerOfTwo(n/2) && n%2 == 0)
        {
            return true;
        }
        else 
        {
        return false;
        }
    }
};