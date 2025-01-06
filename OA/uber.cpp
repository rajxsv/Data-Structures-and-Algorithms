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

void fall(vector<vector<int>> &bub, int i, int j) {
    int x = i;
    for (; x>1; x--) {
        if(bub[x-1][j]==0) break;
        bub[x][j]=bub[x-1][j];
    }
    for (;x>=0; x--) {
        bub[x][j]=0;
    }
}

void operate(vector<vector<int>> &bub, int i, int j) {
    if (i-1>=0 && j-1>=0 && bub[i-1][j-1]==bub[i][j]) {
        bub[i-1][j-1]=0;
        fall(bub,i-1,j-1);    
    }
    if (i-1>=0 && j+1<bub[0].size() && bub[i-1][j+1]==bub[i][j]) {
        bub[i-1][j+1]=0;
        fall(bub,i-1,j+1);        
    }
    if (i+1<bub.size() && j-1>=0 && bub[i+1][j-1]==bub[i][j]) {
        bub[i+1][j-1]=0;
        fall(bub,i+1,j-1);            
    }
    if (i+1<bub.size() && j+1<bub[0].size() && bub[i+1][j+1]==bub[i][j]) {
        bub[i+1][j+1]=0;
        fall(bub,i+1,j+1);            
    }
}

void solve() {

    vector<vector<int>> bub = {  {1,1,1,4,3},
                                 {4,1,2,3,3},
                                 {1,5,1,1,2},
                                 {4,3,2,2,4}
                            };

    vector<vector<int>> op = {{1,1},{3,3},{2,2},{3,0}};

    operate(bub,1,1);

    for (auto it:op) {
        int i = it[0];
        int j = it[1];

        operate(bub,i,j);
    }

    for (int i=0; i<bub.size(); i++) {
        for (int j=0; j<bub[0].size(); j++) {
            cout << bub[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{

    int t=1;

    while(t--){
        solve();
    }
    return 0;

}