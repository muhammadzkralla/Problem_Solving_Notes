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

void solve() {
    ll n, m, x, ans = LLONG_MIN, petals = 0;
    cin >> n >> m;
    vector<ll> v(n);
    map<ll, ll> freq;
    set<ll> st;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        st.insert(v[i]);
    }

    for (int i = 0; i < n; ++i) {
        cin >> x;
        freq[v[i]] = x;
    }

    for (auto num : st) {
        // take as much as you can from ( num )
        ll mul1 = min(m / num, freq[num]);
        petals = mul1 * num;

        if (st.find(num + 1) != st.end()) {
            ll remaining_coins = m - petals, mul2 = 0;

            // take as much as you can from ( num + 1 )
            if (remaining_coins >= num + 1) {
                mul2 = min(remaining_coins / (num + 1), freq[num + 1]);
                petals += mul2 * (num + 1);
                remaining_coins = m - petals;
            }

            // we have already taken (mul1) items of (num) and
            // we took (mul2) items of (num + 1)
            // so we can replace the remaining items of (num + 1)
            // with the already taken (mul1) items of (num)
            ll can_be_replaced = min(freq[num + 1] - mul2, mul1);

            // but we can not replace all the remaining (num)
            // we took by (num + 1) as we are limited by the
            // the remaining coins we still have
            petals += min(remaining_coins, can_be_replaced);
            // notice that we are not multiplying by (num + 1)
            // or removing the old (num) as replacing (num)
            // with (num + 1) is equivalent of adding 1 to the answer
        }

        ans = max(ans, petals);
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