#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define int int64_t
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
const int MOD = 1000000007LL;
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
unordered_map<int, int> mp;
void update(int x) { mp[x]++; }
bool query(int x) { return mp.count(x); }
void erase(int x) { mp.erase(x); }
void run_case() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }
  while (q--) {
    int x;
    cin >> x;
    cout << mp[x] << endl;
  }
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
