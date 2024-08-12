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
const ll oo = 2e15 + 20;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<vector<ll>> adj(2e5 + 20);
vector<ll> a;

bool dfs(ll idx, ll ans) {
    // if leaf and its value is less than ans, this ans is invalid
    if (adj[idx].empty() && a[idx] < ans) return false;

    // if we are at the root and it's already greater than or equal the answer, the answer is true
    // if we are at the root and it's less than the answer, then we need to increment it by (ans - root)
    // if we are not at the root, and the current node is less than the answer, then we need to increment it
    // by ans + (ans - a[idx]) and the min part to avoid overflow.
    if (idx == 0 && a[0] >= ans) return true;
    else if (idx == 0) ans = (ans - a[idx]);
    else if (a[idx] < ans) ans = min((ll) 1e15, ans + (ans - a[idx]));

    for (auto u : adj[idx]) if (!dfs(u, ans)) return false;

    return true;
}

void solve() {
    ll n;
    cin >> n;
    a.resize(n);
    vector<ll> p(n - 1);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> p[i];
    for (int i = 0; i < n - 1; ++i) adj[p[i] - 1].push_back(i + 1);

    ll l = 0, ans = a[0], r = oo;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (dfs(0, mid)) {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else r = mid - 1;
    }

    for (int i = 0; i < n; i++) adj[i].clear();

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