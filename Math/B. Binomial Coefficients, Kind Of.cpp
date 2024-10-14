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

#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll mod_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    ll t;
    cin >> t;
    vector<vector<ll>> c(2, vector<ll>(t));
    for (int i = 0; i < t; ++i) {
        cin >> c[0][i];
    }

    for (int i = 0; i < t; ++i) {
        cin >> c[1][i];
    }

    for (int i = 0; i < t; ++i) {
        ll n = c[0][i], r = c[1][i];
        if (n == r) cout << 1ll << endl;
        else {
            ll ans = mod_pow(2, r);
            cout << ans << endl;
        }
    }
}

int main() {
    fast();
    int t = 1;
//     cin >> t;
    while (t--) {
        solve();
    }
}
