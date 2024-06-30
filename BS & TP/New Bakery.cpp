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
    ll n, a, b, ans = LLONG_MIN;
    cin >> n >> a >> b;

    if (b <= a) {
        cout << a * n << endl;
        return;
    }

    ll l = 0, r = min(n, b - a);
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll curr_profit = 0;

//        for (ll i = 0; i < mid; ++i)
//            curr_profit += (b - i);
//        for (ll i = mid; i < n; ++i)
//            curr_profit += a;

        // instead of the two loops
        curr_profit += mid * b - (mid * (mid - 1)) / 2;
        curr_profit += a * (n - mid);

        if (curr_profit > ans) {
            ans = curr_profit;
            l = mid + 1;
        } else r = mid - 1;

    }

    cout << ans << endl;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}