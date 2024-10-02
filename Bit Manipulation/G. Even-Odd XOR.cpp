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
#include <vector>

#define ll long long
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, start;
    cin >> n;
    vector<ll> odd, even;
    if ((n & 1)) {
        odd.resize((n / 2) + 1, 0), even.resize(n / 2, 0);
        for (int i = 1; i <= n / 2; ++i) {
            odd[i] = i; even[i - 1] = i;
        }

        if (!(((n / 2) + 1) & 1)) {
            // set 30th bit in all items
            for (int i = 0; i <= n / 2; ++i) {
                odd[i] |= (1 << 30);
            }
        } else {
            // set the 30th bit in all items except last
            for (int i = 0; i < (n / 2); ++i) {
                odd[i] |= (1 << 30);
            }

            // set the 29th bit in all items except first
            for (int i = 1; i <= (n / 2); ++i) {
                odd[i] |= (1 << 29);
            }
        }
    } else {
        odd.resize(n / 2, 0), even.resize(n / 2, 0);
        for (int i = 0; i < n / 2; ++i) {
            odd[i] = i + 1, even[i] = i + 1;
        }

        // the same goes here
        if (!((n / 2) & 1)) {
            for (int i = 0; i < n / 2; ++i) {
                odd[i] |= (1 << 30);
            }
        } else {
            for (int i = 0; i < (n / 2) - 1; ++i) {
                odd[i] |= (1 << 30);
            }

            for (int i = 1; i < (n / 2); ++i) {
                odd[i] |= (1 << 29);
            }
        }
    }

    for (int i = 0; i < n / 2; ++i) {
        cout << odd[i] << " " << even[i] << " ";
    }

    if ((n & 1)) cout << odd[n / 2];
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

