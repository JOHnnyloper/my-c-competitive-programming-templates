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
const int MAXN = 1000005;
bool isPrime[MAXN + 1];
void era(int n) {
  for (int i = 0; i <= n; i++)
    isPrime[i] = true;
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; 1LL * i * i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
}
signed main() {
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(NULL);
  int n;
  cin >> n;
  era(n);
  for (int i = 2; i <= n; ++i) {
    if (isPrime[i])
      cout << i << ' ';
  }
  return 0;
}
