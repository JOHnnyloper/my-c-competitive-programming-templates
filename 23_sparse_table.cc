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
const int LOG = 20;
const int MAXN = 1e5 + 5;
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
int n, q;
int a[MAXN];
int st[MAXN][LOG + 1];
void build() {
  for (int i = 1; i <= n; i++)
    st[i][0] = a[i];
  for (int j = 1; j <= LOG; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int query(int l, int r) {
  int k = __lg(r - l + 1);
  return min(st[l][k], st[r - (1 << k) + 1][k]);
}
void run_case() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build();
  while (q-- > 0) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << endl;
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
