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
#include <vector>

#define ll long long
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, l, r, x, ans = 0;
    cin >> n >> l >> r >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    // 2 to the power of n cases
    for (int i = 0; i < (1 << n); ++i) {
        ll mx = LLONG_MIN, mn = LLONG_MAX, cnt = 0, sum = 0;

        for (int j = 0; j < n; ++j) {
            // whether the j-th item is included in this permutation or not
            if (( (i >> j) & 1 )) {
                cnt++;
                sum += v[j];
                mx = max(mx, v[j]);
                mn = min(mn, v[j]);
            }
        }

        if (cnt >= 2 && sum >= l && sum <= r && mx - mn >= x) ans++;
    }

    cout << ans << endl;
}

int main() {
    fast();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

