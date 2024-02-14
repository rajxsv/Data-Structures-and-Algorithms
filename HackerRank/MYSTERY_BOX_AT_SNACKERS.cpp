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

void solve() {

  int n;
  cin >> n;

  int cur = 1;
  vector<int> res(n,-1);
  vector<int> nums(n);
  vector<int> avail(n+1,1);

  for(int i=0; i<n; i++) {
    cin >> nums[i];
  } 

  res[0] = nums[0];
  avail[nums[0]] = 0;

  for(int i=1; i<n; i++) {
    if(nums[i-1] == nums[i]) continue;
    res[i] = nums[i];
    avail[nums[i]] = 0;
  }

  for(int i=1; i<n; i++) {
    if(res[i] == -1) {
      for(int candidate = res[i-1]-1; candidate>=1; candidate--) {
        if(avail[candidate]) {
          res[i] = candidate;
          avail[candidate] = 0;
          break;
        }
      }

      if(res[i] == -1) {
        cout << -1 << endl;
        return;
      }
    }
  }

  for(auto i : res) {
    cout << i << " ";
  }

  cout << endl;

}

int main()
{


  solve();

  return 0;

}