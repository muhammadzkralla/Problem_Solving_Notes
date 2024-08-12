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

bool can(vector<ll> indices, vector<ll> a, vector<ll> sorted, ll target, ll k) {
    
}

void solve() {
    ll n, k, ans = LLONG_MIN;
    cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; ++i) cin >> ab[i].first;
    for (int i = 0; i < n; ++i) cin >> ab[i].second;

    sort(ab.begin(), ab.end());

    // med1 will be the median when we remove any number before n / 2
    // med2 will be the medial when we remove any number after n / 2
    ll med1 = (n / 2), med2 = (n / 2) - 1;
    for (int i = 0; i < n; ++i) {
        // check if we gave all the k to the current number (maximize the a)
        if (ab[i].second == 1) {
            if (i < n / 2) ans = max(ans, (ab[i].first + k) + ab[med1].first);
            else ans = max(ans, (ab[i].first + k) + ab[med2].first);
        }
    }

    // binary search the maximum median we can achieve (maximize the median)
    ll l = 0, r = 1e10;
    while (l <= r) {
        ll mid = l + (r - l) / 2;

        // the count of numbers greater than or equal mid
        ll count = 0;
        vector<ll> need;
        for (int i = 0; i < n - 1; ++i) {
            if (ab[i].first >= mid) count++;
            else if (ab[i].second == 1) need.push_back(mid - ab[i].first);
        }

        // change nearest numbers to mid first
        reverse(need.begin(), need.end());

        // lets try and increment numbers we can and see if we can make them equal mid
        ll tmp = k;
        for (auto i : need) {
            if (i <= tmp) {
                tmp -= i;
                count++;
            }
        }
        
        // if count is greater than or equal (n + 1) / 2, there must be mid at the median
        if (count >= (n + 1) / 2) {
            l = mid + 1;
            ans = max(ans, ab[n - 1].first + mid);
        }
        else r = mid - 1;
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