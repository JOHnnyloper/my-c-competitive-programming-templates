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
const int MAXN = 200005;
int parent_[MAXN], sz[MAXN];
struct Edge {
  int u, v;
  ll w;
};
int find_root(int u) {
  if (parent_[u] == u)
    return u;
  return parent_[u] = find_root(parent_[u]);
}
bool unite(int u, int v) {
  u = find_root(u);
  v = find_root(v);
  if (u == v)
    return false;
  if (sz[u] < sz[v])
    swap(u, v);
  parent_[v] = u;
  sz[u] += sz[v];
  return true;
}
void run_case() {
  int n, m;
  cin >> n >> m;
  vector<Edge> e(m);
  for (int i = 0; i < m; i++)
    cin >> e[i].u >> e[i].v >> e[i].w;
  sort(e.begin(), e.end(), [](Edge a, Edge b) { return a.w < b.w; });
  for (int i = 1; i <= n; i++)
    parent_[i] = i, sz[i] = 1;
  ll ans = 0;
  int used = 0;
  for (auto x : e) {
    if (unite(x.u, x.v)) {
      ans += x.w;
      used++;
    }
  }
  if (used != n - 1)
    cout << "IMPOSSIBLE\n";
  else
    cout << ans << endl;
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
