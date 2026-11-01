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
// this
const int MAXN = 200005;
ll bit[MAXN];
int n;
void update(int i, ll value) {
  while (i <= n) {
    bit[i] += value;
    i += i & -i;
  }
}
ll query(int i) {
  ll sum = 0;
  while (i > 0) {
    sum += bit[i];
    i -= i & -i;
  }
  return sum;
}
ll range_sum(int l, int r) { return query(r) - query(l - 1); }
void run_case() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    update(i, x);
  }
  int q;
  cin >> q;
  while (q--) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 1)
      update(x, y);
    else
      cout << range_sum(x, y) << endl;
  }
}
signed main() {
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(NULL);
  run_case();
  return 0;
}
