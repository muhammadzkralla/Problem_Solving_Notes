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

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 1; i < n - 2; ++i) {
        // 2 1 : if both already bad and swapping eliminate one or both
        if (v[i] == v[i - 1] && v[n - i - 1] == v[n - i]) {
            if (v[i] != v[n - i] || v[n - i] != v[i - 1]) {
                swap(v[i], v[n - i - 1]);
                continue;
            }
        }

        // 1 0 : if one bad and swapping eliminate it
        if (v[i] == v[i - 1] || v[n - i - 1] == v[n - i]) {
            if (v[i] != v[n - i] && v[n - i] != v[i - 1]) {
                swap(v[i], v[n - i - 1]);
                continue;
            }
        }
    }

    for (int i = 0; i < n - 1; ++i)
        if (v[i] == v[i + 1])
            ans++;

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
