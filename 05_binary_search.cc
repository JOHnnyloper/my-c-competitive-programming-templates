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
int a[MAXN];
int first_ge(int n, int x) {
  int l = 1, r = n + 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
int first_gt(int n, int x) {
  int l = 1, r = n + 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] > x)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
signed main() {
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  while (q--) {
    int x;
    cin >> x;
    int L = first_ge(n, x);
    int R = first_gt(n, x);
    cout << "Number of occurrences: " << R - L << endl;
  }
  return 0;
}
