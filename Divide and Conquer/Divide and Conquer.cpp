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

bool isMultiple(ll x, ll y) {
    return (y % x == 0 || x % y == 0);
}

ll divideAndConquer(ll l, ll w) { // NOLINT(misc-no-recursion)
    if (isMultiple(w, l)) return min(w, l);

    ll mn = min(l, w), mx = max(l, w), diff = mx / mn;
    return divideAndConquer(mn, mx - (diff * mn));
}

void solve() {
    ll l, w;
    cin >> l >> w;
    cout << divideAndConquer(l, w) << endl;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}