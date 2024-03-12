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
    ll n, x, first, second = -1;
    cin >> n >> x;
    vector<ll> v(n);
    vector<pair<ll, ll>> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp.emplace_back(i, v[i]);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; ++i) {
        ll diff = x - v[i], l = i + 1, r = n - 1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;

            if (v[mid] == diff) {
                first = v[i];
                second = v[mid];
                break;
            }

            if (v[mid] < diff) l = mid + 1;
            else r = mid - 1;
        }

        if (second != -1) {
            bool flag1 = true, flag2 = true;
            for (int j = 0; j < n; ++j) {
                if (flag1 && mp[j].second == first) {
                    first = j + 1;
                    flag1 = false;
                }
                else if (flag2 && mp[j].second == second) {
                    second = j + 1;
                    flag2 = false;
                }
            }

            cout << first << " " << second << endl;
            return;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    fast();
    int t = 1;
    while (t--){
        solve();
    }
}