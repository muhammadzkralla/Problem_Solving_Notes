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

ll gcd(ll a, ll b) { // NOLINT(misc-no-recursion)
    if (b == 0) return a;
    return (gcd(b, a % b));
}

bool isIncreasing(vector<ll> v) {
    for (int i = 1; i < v.size(); ++i)
        if (v[i] < v[i - 1])
            return false;

    return true;
}

bool check(ll idx, vector<ll> v) {
    for (int i = 0; i < 3; ++i) {
        vector<ll> a = v;
        a.erase(a.begin() + idx + i);
        vector<ll> b;

        for (int j = 1; j < a.size(); ++j) b.push_back(gcd(a[j], a[j - 1]));
        if (isIncreasing(b)) return true;

    }
    return false;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) b.push_back(gcd(a[i], a[i - 1]));

    for (int i = 1; i < n - 1; ++i) {
        if (b[i] < b[i - 1]) {
            if (check(i - 1, a)) cout << "YES" << endl;
            else cout << "NO" << endl;

            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}