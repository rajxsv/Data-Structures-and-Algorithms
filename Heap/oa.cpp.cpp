#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>

#define f(i,s,e) for(long long int i=s;i<e;i++)

template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int solution(string s) {
    int n = s.length();
    vector<vector<int>>dp(n,vector<int>(n,0));
    int maxLen = 0;
    string ans;

    for(int diff = 0 ; diff<n ; diff++){
        for(int i=0,j=i+diff ; j<n ; i++,j++){
            if((j-i+1)&1) {
                continue;
            }
            if(i==j){
                dp[i][j]=1;
            }
            else if(diff==1){
                dp[i][j] = ((s[i] == '<' && s[j] == '>') || (s[i] == '?' && s[j] == '>')  || (s[i] == '<' && s[j] == '?'))?2:0;
            }
            else {
                if(((s[i] == '<' && s[j] == '>') || (s[i] == '?' && s[j] == '>')  || (s[i] == '<' && s[j] == '?') ||
                     (s[i] == '?' && s[j] == '?')) && dp[i+1][j-1])
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            if(dp[i][j]>maxLen){
                maxLen = j-i+1;
            }
        }
    }
    return maxLen;
}

void solve() {
    string s;
    cin >> s;
    cout << solution(s) << endl;

}

int main()
{
    solve();
    return 0;

}