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
ll st[4 * MAXN], a[MAXN];
void build(int id, int l, int r) {
  if (l == r) {
    st[id] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  st[id] = st[id * 2] + st[id * 2 + 1];
}
void update(int id, int l, int r, int pos, ll value) {
  if (l == r) {
    st[id] = value;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid)
    update(id * 2, l, mid, pos, value);
  else
    update(id * 2 + 1, mid + 1, r, pos, value);
  st[id] = st[id * 2] + st[id * 2 + 1];
}
ll query(int id, int l, int r, int u, int v) {
  if (v < l || r < u)
    return 0;
  if (u <= l && r <= v)
    return st[id];
  int mid = (l + r) / 2;
  return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

void run_case() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);

  while (q--) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 1)
      update(1, 1, n, x, y);
    else
      cout << query(1, 1, n, x, y) << endl;
  }
}
signed main() {
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(NULL);
  run_case();
  return 0;
}
