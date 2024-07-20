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

using namespace std;
auto mod = 1e9 + 7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, x, ans = 0;
    cin >> n >> x;
    vector<ll> v(n), pref(n + 1), dp(n + 2);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pref[i + 1] = pref[i] + v[i];
    }

    for (ll i = n - 1; i >= 0; --i) {
        // find such a minimum j that the sum on the subsegment i -> j is greater than x
        ll val = pref[i] + x;
        ll j = upper_bound(pref.begin(), pref.end(), val) - pref.begin();

        // the number of valid subsegments starting from i is equal to
        // all the subsegments from i -> j and the number of valid subsegments starting with j
        dp[i] = j - i - 1 + dp[j];
        ans += dp[i];
    }

    cout << ans << endl;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}