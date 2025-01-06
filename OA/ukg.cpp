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
string res = "";

void computeAns(vector<string> ans) {
    sort(begin(ans),end(ans),greater<string>());
    string smallRes = "";
    for(auto s:ans){
        smallRes+=s;
    }
    res=max(smallRes,res);
}

void largestSubstring(string s, vector<string> ans) {
    if (s.size()==0){
        computeAns(ans);
        return;
    }
    int n=s.size();
    int o=0, z=0;
    for (int i=0; i<n; i++) {
        o+=s[i]=='1';
        z+=s[i]=='0';
        if (o>=z) {
            ans.push_back(s.substr(0,i+1));
            largestSubstring(s.substr(i+1),ans);
            ans.pop_back();
        }
    }
}

void solve() {
    string s;
    cin >> s;
    vector<string> ans;
    largestSubstring(s,ans);
    cout << res << endl;
}

int main()
{

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;

}