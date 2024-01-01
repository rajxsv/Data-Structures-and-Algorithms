#include<bits/stdc++.h>
#define DELIM ' '
using namespace std;



int main(){

    string s = "generate aaa 1";

    stringstream ss(s);
    string token;

    vector<string> tokens;

    while(getline(ss, token, DELIM)){
        tokens.push_back(token);
    }
    int n = tokens.size();

    for(int i=n-10; i<n; i++){
        cout << tokens[i] << endl;
    }

    return 0;
}