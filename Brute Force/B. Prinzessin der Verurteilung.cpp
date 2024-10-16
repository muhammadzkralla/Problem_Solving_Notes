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

set<string> comb;

void preprocess() {
    for (int i = 0; i < 26; ++i)
        comb.insert(string(1, 'a' + i));
    for (int i = 0; i < 26; ++i) 
        for (int j = 0; j < 26; ++j)
            comb.insert(string(1, 'a' + i) + string(1, 'a' + j));
    for (int i = 0; i < 26; ++i) 
        for (int j = 0; j < 26; ++j)
            for(int k = 0; k < 26; ++k)
                comb.insert(string(1, 'a' + i) + string(1, 'a' + j) + string(1, 'a' + k));
}

void solve() {
    ll n;
    string s, ans = "~";
    cin >> n >> s;

    for(auto st : comb)
        if (s.find(st) == string::npos)
            if (st.size() < ans.size() || st < ans)
                ans = st;

    cout << ans << endl;
}

int main() {
    fast();
    preprocess();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
