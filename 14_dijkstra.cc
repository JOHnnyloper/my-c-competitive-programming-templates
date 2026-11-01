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
const ll INF = 0x7fffffffffffffffLL;
const int MAXN = 200005;
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
vector<pair<int, ll>> adj[MAXN];
ll dist_[MAXN];
void dijkstra(int s, int n) {
  fill(dist_, dist_ + n + 1, INF);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  dist_[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    ll d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (d != dist_[u])
      continue;
    for (auto e : adj[u]) {
      int v = e.first;
      ll w = e.second;
      if (dist_[v] > d + w) {
        dist_[v] = d + w;
        pq.push({dist_[v], v});
      }
    }
  }
}
void run_case() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dijkstra(1, n);
  for (int i = 1; i <= n; i++) {
    if (dist_[i] == INF)
      cout << -1 << ' ';
    else
      cout << dist_[i] << ' ';
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
