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
bool isPrime[MAXN + 1];
int pref[MAXN + 1];
void era(int n) {
  fill(isPrime, isPrime + n + 1, true);
  if (n >= 0)
    isPrime[0] = false;
  if (n >= 1)
    isPrime[1] = false;
  for (int i = 2; 1LL * i * i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i)
        isPrime[j] = false;
    }
  }
  pref[0] = 0;
  for (int i = 1; i <= n; i++)
    pref[i] = pref[i - 1] + isPrime[i];
}
signed main() {
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  era(n);
  while (q--) {
    int l, r;
    cin >> l >> r;
    l = max(l, int(1));
    r = min(r, int(n));
    if (l > r)
      cout << 0 << endl;
    else
      cout << pref[r] - pref[l - 1] << endl;
  }
  return 0;
}
