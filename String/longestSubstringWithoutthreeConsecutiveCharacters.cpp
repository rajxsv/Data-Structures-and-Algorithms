#include<iostream>
using namespace std;

string solve(string s){
    int n = s.size();
    int start = 0;
    int c = 0;

    char prev = s[0];

    string ans = "";

    for(int i=0;i<n;i++){
        if(s[i] == prev && c<2){
            c++;
            ans += s[i];
        }else if(s[i] == prev){
            while(i<n && s[i]==prev){
                i++;
            }
            c=0;
            prev = s[i];
            i--;
        }else{
            prev = s[i];
            c = 1;
            ans += s[i];
        }
    }
    return ans;
}

int main(){

    string s = "uuuuxaaaaxum";

    cout << solve(s) << endl;


    return 0;
}