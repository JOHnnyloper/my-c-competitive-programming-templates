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
const int MAXN = 1000000;
int spf[MAXN + 1];
void build_spf(int n) {
  for (int i = 0; i <= n; i++)
    spf[i] = i;
  if (n >= 1)
    spf[1] = 1;
  for (int i = 2; 1LL * i * i <= n; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= n; j += i) {
        if (spf[j] == j)
          spf[j] = i;
      }
    }
  }
}
void factorize(int x) {
  while (x > 1) {
    int p = spf[x];
    int cnt = 0;
    while (x % p == 0) {
      x /= p;
      cnt++;
    }
    cout << p << '^' << cnt << ' ';
  }
  cout << endl;
}
signed main() {
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(NULL);
  int n, x;
  cin >> n >> x;
  build_spf(n);
  factorize(x);
  return 0;
}
