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

ll bs(ll x, vector<ll> arr) {
    ll l = 0, r = (ll) arr.size() - 1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return -1;
}

void solve() {
    ll n, m;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    cin >> m;
    vector<ll> d(m);
    for (int i = 0; i < m; ++i) cin >> d[i];

    // mset to allow duplicates while maintaining order
    multiset<ll> md;

    // calculate modifications
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i])
            md.insert(b[i]);

    // sort b to do bs later
    sort(b.begin(), b.end());

    // plot modifications from the end to the beginning
    bool hasMod = false;
    for (ll i = m - 1; i >= 0; --i) {
        auto it = md.find(d[i]);

        if (it != md.end()) {
            md.erase(it);
            hasMod = true;
        }

        // if not modified earlier check if b already has the d[i] or not.
        if (!hasMod) {
            ll idx = bs(d[i], b);

            if (idx == -1) {
                cout << "NO" << endl;
                return;
            }

            hasMod = true;
        }
    }

    if (md.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}