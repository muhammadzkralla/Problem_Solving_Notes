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

string operate(string s, bool flag) {
    while (true) {
        bool changed = false;
        string new_s = "";

        for (int i = 0; i < s.length(); ++i) {
            if (i + 1 < s.length() &&
                ((s[i] == '1' && s[i + 1] == '0') || (s[i] == '0' && s[i + 1] == '1'))) {
                new_s += (flag ? '1' : '0');
                flag = !flag;
                ++i;
                changed = true;
            } else {
                new_s += s[i];
            }
        }

        if (!changed) break;
        s = new_s;
    }

    return s;
}

void solve() {
    ll n;
    string s, ans;
    cin >> n >> s;
    if (s[0] == '1' || s[n - 1] == '1') cout << "YES" << endl;
    else {
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '1' && s[i + 1] == '1') {
                cout << "YES" << endl;
                return;
            }
        }

        cout << "NO" << endl;
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
