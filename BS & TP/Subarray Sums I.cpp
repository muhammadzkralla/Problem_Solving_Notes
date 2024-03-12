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

struct node {
    int x;
    int y;
    bool operator<(const node& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

void solve() {
    ll n, x, ans = 0;
    cin >> n >> x;
    vector<ll> v(n), pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pref[i + 1] = pref[i] + v[i];
    }

    for (int i = 0; i <= n; ++i) {
        ll diff = pref[i] - x;
        if (diff < 0) continue;

        ll l = 0, r = n;
        while (l <= r) {
            ll mid = l + (r - l) / 2;

            if (pref[mid] == diff) {
                ans++;
                break;
            }

            if (pref[mid] < diff) l = mid + 1;
            else r = mid - 1;
        }
    }

    cout << ans << endl;
}

int main() {
    fast();
    int t = 1;
    while (t--){
        solve();
    }
}