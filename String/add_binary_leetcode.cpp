#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
        
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        string ans = "";
        int k = 0;
        int carry=0;
       
        while(i>=0 || j >= 0 || carry)
        {
            int sum = 0;
            
            if(i>=0)
            {
                sum += (int)(a[i]-'0');
                i--;
            }
            if(j>=0)
            {
                sum += (int)(b[j]-'0');
                j--;
            }
                  
            sum += carry;
            carry = sum >> 1;   //sum/2
            //char temp = (sum & 1) + '0';
            ans += (char)((sum & 1) + '0');
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
int main(){
	string a = "101" ;
	string b = "1"; 
	
	cout << addBinary(a,b)<<endl;

	return 0;
}