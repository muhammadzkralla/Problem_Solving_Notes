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
#include <climits>

#define ll long long
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, sum = 0, ans = LLONG_MAX;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    if (n == 1) {
        cout << -1 << endl;
        return;
    }

    sort(v.begin(), v.end());
    if (n / 2 == n - 1) {
        cout << -1 << endl;
        return;
    }

    ll l = 0, r = 1e12;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        double avg = (double) ((double) sum + (double) mid) / (double) n;
        avg /= (double) 2;

        if (v[n / 2] < avg) {
            ans = min(ans, mid);
            r = mid - 1;
        } else l = mid + 1;
    }

    if (ans == LLONG_MAX) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
