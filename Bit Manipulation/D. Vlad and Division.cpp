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

int flipBits2(int n, int k) {
    int mask = (1 << k) - 1;
    return ~n & mask;
}

void solve() {
    int n;
    cin >> n;
    map<ll, ll> freq;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        freq[v[i]]++;
    }

    ll ans = n;
    for (auto i : v) {
        ll comp = flipBits2(i, 31);
        ll mn = min(freq[i], freq[comp]);
        freq[i] -= mn; freq[comp] -= mn; ans -= mn;
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