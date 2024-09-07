/**
    /$$$$$$$$
|_____ $$
        /$$/
    /$$/
    /$$/
    /$$/
    /$$$$$$$$
|________/
**/

#include <bits/stdc++.h>
#include <climits>
#define ll long long
using namespace std;

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

ll sum(ll m, ll n) { return ((m - n + 1) * (n + m)) / 2; }

void solve() {
  ll n, k, ans = LLONG_MAX;
  cin >> n >> k;

  ll l = 0, r = 1e9;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    ll first = sum(k + mid, k);
    ll second = sum(k + n - 1, k + mid + 1);
    ll tmp = first - second;

    if (tmp > 0) {
      ans = min(ans, tmp);
      r = mid - 1;
    } else {
      l = mid + 1;
      ans = min(ans, abs(tmp));
    }
  }

  cout << ans << endl;
}

int main() {
  fast();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
