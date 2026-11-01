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
vector<int> build_lps(const string &p) {
  int m = (int)p.size();
  vector<int> lps(m, 0);
  int len = 0;
  for (int i = 1; i < m;) {
    if (p[i] == p[len])
      lps[i++] = ++len;
    else if (len > 0)
      len = lps[len - 1];
    else
      lps[i++] = 0;
  }
  return lps;
}
void run_case() {
  string text, pattern;
  cin >> text >> pattern;
  if (pattern.empty())
    return;
  vector<int> lps = build_lps(pattern);
  int i = 0, j = 0;
  while (i < (int)text.size()) {
    if (text[i] == pattern[j])
      i++, j++;
    if (j == (int)pattern.size()) {
      cout << i - j << ' ';
      j = lps[j - 1];
    } else if (i < (int)text.size() && text[i] != pattern[j]) {
      if (j > 0)
        j = lps[j - 1];
      else
        i++;
    }
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
