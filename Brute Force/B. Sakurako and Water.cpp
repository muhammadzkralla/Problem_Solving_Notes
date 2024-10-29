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

const ll mod = 1e9 + 7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// O(n^2) solution
void solve() {
    ll n, ans = 0;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];

    for (int i = 1; i <= n; ++i) {
        ll curr1 = 0, curr2 = 0;
        for (int j = 0; j < n; ++j) {
            // if current item is invalid
            if (n - i + j == n || j == n) break;

            // check both the lower and the upper diagonal at the same time
            if (v[n - i + j][j] < 0) curr1 = min(curr1, v[n - i + j][j]);
            if (i != n && v[j][n - i + j] < 0) curr2 = min(curr2, v[j][n - i + j]);
        }

        ans -= curr2;
        ans -= curr1;
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
