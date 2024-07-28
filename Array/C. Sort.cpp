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
    ll n, q, l, r;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<pair<ll, ll>> queries;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        queries.emplace_back(l, r);
    }

    // prefix sum array to keep track of the count of the occurence of each char in both strings
    // untill a certain index
    vector<vector<ll>> pref1(n + 1, vector<ll>(26));
    vector<vector<ll>> pref2(n + 1, vector<ll>(26));

    for (int i = 1; i <= n; ++i) {
        ll curr = (a[i - 1] - 'a');
        pref1[i][curr]++;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 26; j++)
            pref1[i][j] += pref1[i - 1][j];
    

    for (int i = 1; i <= n; ++i) {
        ll curr = (b[i - 1] - 'a');
        pref2[i][curr]++;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 26; j++)
            pref2[i][j] += pref2[i - 1][j];
    
    for (auto query : queries) {
        l = query.first, r = query.second;

        ll ans = 0;
        // for each characted form a -> z
        for (int i = 0; i < 26; ++i) {
            // count of the occurence of this character from l -> r in both strings
            ll cnt1 = pref1[r][i] - pref1[l - 1][i];
            ll cnt2 = pref2[r][i] - pref2[l - 1][i];

            ans += abs(cnt1 - cnt2);
        }

        cout << ans / 2 << endl;

    }

}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}