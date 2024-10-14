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

const ll mod = 1e9 + 7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll mod_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    ll n, k, ans = LLONG_MIN;
    cin >> n >> k;
    vector<ll> v(n);
    map<ll, ll> freq;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        freq[v[i]]++;
    }

    sort(v.begin(), v.end());

    ll curr = v[0], streak = 1, unique = 1;
    queue<ll> st;
    st.push(curr);
    for (int i = 1; i < n; ++i) {
        if (v[i] == curr) streak++;
        else if (v[i] == curr + 1) {
            if (unique < k) {
                st.push(v[i]);
                curr = v[i];
                streak++;
                unique++;
            } else {
                ans = max(ans, streak);
                ll first = st.front();
                st.pop();
                streak -= freq[first];
                curr = v[i];
                st.push(v[i]);
                streak++;
            }
        } else {
            ans = max(ans, streak);
            while (!st.empty()) st.pop();
            st.push(v[i]);
            streak = 1;
            unique = 1;
            curr = v[i];
        }
    }

    ans = max(ans, streak);

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
