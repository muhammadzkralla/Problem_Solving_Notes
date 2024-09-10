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

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, x, y, ans = 0;
    cin >> n;

    set<ll> zeroes;
    set<ll> ones;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (y == 0) zeroes.insert(x);
        else ones.insert(x);
    }

    for (auto i : ones) {
        if (zeroes.find(i) != zeroes.end()) {
            ans += n - 2;
        }
    }

    for (auto i : ones) {
        if (zeroes.find(i - 1) != zeroes.end()) {
            if (zeroes.find(i + 1) != zeroes.end()) {
                ans++;
            }
        }
    }

    for (auto i : zeroes) {
        if (ones.find(i - 1) != ones.end()) {
            if (ones.find(i + 1) != ones.end()) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
