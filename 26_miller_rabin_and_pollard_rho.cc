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
// here
int mul(int a, int b, int mod) { return (__int128)a * b % mod; }
int power(int a, int b, int mod) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = mul(res, a, mod);
    a = mul(a, a, mod);
    b >>= 1;
  }
  return res;
}
// Miller Rabin
bool is_prime(int n) {
  if (n < 2)
    return false;
  for (int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n % p == 0)
      return n == p;
  }
  int d = n - 1, s = 0;
  while (!(d & 1)) {
    d >>= 1;
    ++s;
  }
  for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    if (a % n == 0)
      continue;
    int x = power(a, d, n);
    if (x == 1 || x == n - 1)
      continue;
    bool ok = false;
    for (int r = 1; r < s; ++r) {
      x = mul(x, x, n);
      if (x == n - 1) {
        ok = true;
        break;
      }
    }
    if (!ok)
      return false;
  }
  return true;
}
// Pollard Rho
int f(int x, int c, int mod) { return (mul(x, x, mod) + c) % mod; }
int pollard_rho(int n) {
  if (n % 2 == 0)
    return 2;
  if (n % 3 == 0)
    return 3;
  while (true) {
    int x = rng() % (n - 2) + 2;
    int y = x;
    int c = rng() % (n - 1) + 1;
    int d = 1;
    while (d == 1) {
      x = f(x, c, n);
      y = f(f(y, c, n), c, n);
      d = gcd(abs(x - y), n);
    }
    if (d != n)
      return d;
  }
}
// Factorization
void factorize(int n, map<int, int> &fac) {
  if (n == 1)
    return;
  if (is_prime(n)) {
    ++fac[n];
    return;
  }
  int d = pollard_rho(n);
  factorize(d, fac);
  factorize(n / d, fac);
}
void test_case() {
  int n;
  cin >> n;
  map<int, int> fac;
  factorize(n, fac);
  for (auto [p, cnt] : fac) {
    cout << p << "^" << cnt << " ";
  }
  cout << endl;
}
__DEBUG_AND_TEST_CASE__() {
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(NULL);
  int tt = 1;
  scanf("%" SCNd64, &tt);
  while (tt-- > 0) {
    test_case();
  }
  return 0;
}
