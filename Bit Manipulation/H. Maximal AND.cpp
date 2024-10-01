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

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 30; i >= 0; --i) {
        ll cnt = 0;
        for (int j = 0; j < n; ++j) {
            // check if the bit is not set
            if (( (v[j] >> i) & 1 ) == 0) cnt++;
        }
        if (k >= cnt) {
            k -= cnt;
            for (int j = 0; j < n; ++j) {
                // set the bit
                v[j] = v[j] | (1 << i);
            }
        }
    }

    ll ans = v[0];
    for (int i = 1; i < n; ++i) {
        ans &= v[i];
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

