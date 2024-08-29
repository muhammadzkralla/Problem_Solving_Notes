/**
/$$$$$$
|_  $$_/
  | $$    /$$$$$$/$$$$   /$$$$$$    /$$$$$$     /$$$$$$    /$$$$$$$   /$$$$$$$
  | $$   | $$_  $$_  $$ /$$__  $$  /$$__  $$   /$$__  $$  /$$_____/  /$$_____/
  | $$   | $$ \ $$ \ $$ | $$  \ $$ | $$  \__/ | $$$$$$$$ |  $$$$$$  |  $$$$$$
  | $$   | $$ | $$ | $$ | $$  | $$ | $$       | $$_____/  \____  $$  \____  $$
 /$$$$$$ | $$ | $$ | $$ | $$$$$$$/ | $$       |  $$$$$$$  /$$$$$$$/  /$$$$$$$/
|______/ |__/ |__/ |__/ | $$____/  |__/        \_______/ |_______/  |_______/
                        | $$
                        | $$
                        |__/
 **/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <chrono>
#include <numeric>
#define ll long long
#define ld long double

using namespace std;
auto mod = 1e9 + 7;
const ll oo = 2e15 + 20;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, q, l, r;
    cin >> n;
    vector<ll> v(n), dp(n + 1, -1);
    for (int i = 0; i < n; ++i) cin >> v[i];

    ll curr = v[0];
    for (int i = 1; i < n; ++i) {
        if (v[i] != curr) {
            for (int j = i; j >= 0 && dp[j] == -1; --j) {
                dp[j] = i + 1;
            }
            curr = v[i];
        }
    }

    cin >> q;
    while (q--) {
        cin >> l >> r;
        ll ans = dp[l];
        if (ans <= r && ans != -1) cout << l << " " << ans << endl;
        else cout << -1 << " " << -1 << endl;
    }

    cout << endl;

}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}