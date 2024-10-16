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
    ll n, k;
    cin >> n >> k;

    if (n & 1) {
        cout << 1 << " " << n / 2 << " " << n / 2 << endl;
    } else {
        if ((n / 2) + (n / 4) + (n / 4) == n) cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
        else cout << (n / 2) - 1 << " " << (n / 2) - 1 << " " << 2 << endl;
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
