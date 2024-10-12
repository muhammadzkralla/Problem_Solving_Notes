/**
     /$$$$$$$$
    |_____ $$
         /$$/
        /$$/
       /$$/
      /$$/
     /$$$$$$$$
    |________/
 **/

#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>

#define ll long long
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, cnt = 0;
    cin >> n;
    vector<pair<ll, ll>> vp(n);
    for (int i = 0; i < n; ++i) {
        cin >> vp[i].first;
        vp[i].second = i + 1;
    }

    sort(vp.begin(), vp.end());

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (vp[i].first * vp[j].first == (vp[i].second + vp[j].second)) cnt++;
            if (vp[i].first * vp[j].first > (2 * n)) break;
        }
    }

    cout << cnt << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
