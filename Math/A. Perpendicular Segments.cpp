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
#include <vector>

#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll x, y, k, mn;
    cin >> x >> y >> k;

    mn = min(x, y);

    if (k < x && k < y) {
        cout << 0 << " " << 0 << " " << 0 << " " << k << endl;
        cout << 0 << " " << 0 << " " << k << " " << 0 << endl;
    } else {
        cout << 0 << " " << 0 << " " << mn << " " << mn << endl;
        cout << 0 << " " << mn << " " << mn << " " << 0<< endl;
    }
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
