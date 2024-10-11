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
#include <vector>

#define ll long long
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const ll mod = 1e9 + 7;
vector<vector<ll>> dp;
vector<string> grid;

bool isValid(ll r, ll c, ll n) {
    return (r < n && c < n && grid[r][c] != '*');
}

ll backtrack(ll r, ll c, ll n) {
    if (r == n - 1 && c == n - 1) return 1;
    if (dp[r][c] != -1) return dp[r][c];

    ll total = 0;

    if (isValid(r, c + 1, n)) {
        total = (total + backtrack(r, c + 1, n)) % mod;
    }
    if (isValid(r + 1, c, n)) {
        total = (total + backtrack(r + 1, c, n)) % mod;
    }

    dp[r][c] = total;
    return total;
}

void solve() {
    ll n;
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];
    dp.assign(n, vector<ll>(n, -1));

    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
        cout << 0 << endl;
        return;
    }

    ll ans = backtrack(0, 0, n);

    cout << ans << endl;
}

int main() {
    fast();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
