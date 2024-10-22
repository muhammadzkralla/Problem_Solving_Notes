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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        v[i] = {a[i] + b[i], i};
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i){
        ll idx = v[i].second;
        cout << a[idx] << " " << b[idx] << " ";
    }

    cout << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
