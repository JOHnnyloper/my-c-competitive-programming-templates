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
const int MAXN = 2e5 + 5;
const int LOG = 20;
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
int n;
string s;
int sa[MAXN], rk[MAXN];
int tmp[MAXN], lcp[MAXN], pos[MAXN];
void build_sa() {
  n = s.size();
  for (int i = 1; i <= n; i++) {
    sa[i] = i;
    rk[i] = (unsigned char)s[i - 1];
  }
  for (int k = 1; k < n; k *= 2) {
    sort(sa + 1, sa + n + 1, [&](int i, int j) {
      if (rk[i] != rk[j])
        return rk[i] < rk[j];
      int x = (i + k <= n ? rk[i + k] : 0);
      int y = (j + k <= n ? rk[j + k] : 0);
      return x < y;
    });
    tmp[sa[1]] = 1;
    for (int i = 2; i <= n; i++) {
      int u = sa[i - 1];
      int v = sa[i];
      bool diff = (rk[u] != rk[v]);
      int x = (u + k <= n ? rk[u + k] : 0);
      int y = (v + k <= n ? rk[v + k] : 0);
      if (x != y)
        diff = true;
      tmp[v] = tmp[u] + diff;
    }
    for (int i = 1; i <= n; i++)
      rk[i] = tmp[i];
  }
}
void build_lcp() {
  for (int i = 1; i <= n; i++)
    pos[sa[i]] = i;
  int k = 0;
  for (int i = 1; i <= n; i++) {
    int r = pos[i];
    if (r == 1) {
      k = 0;
      continue;
    }
    int j = sa[r - 1];
    while (i + k <= n && j + k <= n && s[i + k - 1] == s[j + k - 1])
      k++;
    lcp[r] = k;
    if (k > 0)
      k--;
  }
}
void run_case() {
  cin >> s;
  build_sa();
  build_lcp();
  for (int i = 1; i <= n; i++)
    cout << sa[i] << " ";
  cout << endl;
  for (int i = 2; i <= n; i++)
    cout << lcp[i] << " ";
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
