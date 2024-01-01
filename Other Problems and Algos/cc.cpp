#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        string s1;
        string s2;
        cin >> s1 >> s2;

        string ans="";
        int n1;
        int n2;
        // ans+="a";
        for(int i=0;i<s1.length();i++){
            n1 = s1[i] - '0';
            n2 = s2[i] - '0';

            int mask=n1&n2;

            if(n1&n2){
                ans+="0";
            }
            else{
                ans+="1";
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}