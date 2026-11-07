#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define int int64_t
#define lb lower_bound
#define ub upper_bound
#define __DEBUG_AND_TEST_CASE__() signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
typedef long long ll;
const int MOD = 1000000007LL;
const int INF = 0x7fffffffffffffffLL;
const int MAXN = 1e5 + 5;
const int LOG = 20;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
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

void test_case() {}
__DEBUG_AND_TEST_CASE__() {
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(NULL);
  int tt;
  scanf("%" SCNd64, &tt);
  while (tt-- > 0) {
    test_case();
  }
  return 0;
}
