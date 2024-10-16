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

#define ll long long
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll ans = 10;
    string s;
    cin >> s;
    ll cnt = count(s.begin(), s.end(), '?');
    ll n = (1 << cnt);

    for (int i = 0; i <= n; ++i) {
        ll curr = 0, a = 0, b = 0, rema = 5, remb = 5;

        for (int j = 0; j < 10; ++j) {

            if (!(j & 1)) {
                if (s[j] == '1') a++;
                else if (s[j] == '?' && (i & (1 << curr++))) a++;
                rema--;
            } else {
                if (s[j] == '1') b++;
                else if (s[j] == '?' && (i & (1 << curr++))) b++;
                remb--;
            }

            if (a > b && a - b > remb) ans = min(ans, j + 1ll);
            else if (b > a && b - a > rema) ans = min(ans, j + 1ll);
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
