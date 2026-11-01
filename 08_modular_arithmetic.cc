#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define int int64_t
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
const ll MOD = 1000000007LL;
const int INF = 0x7fffffffffffffffLL;
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", dbg(__VA_ARGS__)
#else
#define debug(...)
#endif
void dbg() { cerr << endl; }
template <typename T> void dbg(const T &x) { cerr << x << endl; }
template <typename T, typename... U> void dbg(const T &x, const U &...y) {
  cerr << x << " | ";
  dbg(y...);
}
// this
ll mod_pow(ll a, ll b) {
  ll ans = 1;
  a %= MOD;
  while (b > 0) {
    if (b & 1)
      ans = ans * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ans;
}
ll mod_inverse(ll b) { return mod_pow(b, MOD - 2); }
void run_case() {
  ll a, b;
  cin >> a >> b;
  cout << mod_pow(a, b) << endl;
}
signed main() {
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0) {
    run_case();
  }
  return 0;
}
