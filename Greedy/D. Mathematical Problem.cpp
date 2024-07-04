/**
/$$$$$$
|_  $$_/
  | $$    /$$$$$$/$$$$   /$$$$$$    /$$$$$$     /$$$$$$    /$$$$$$$   /$$$$$$$
  | $$   | $$_  $$_  $$ /$$__  $$  /$$__  $$   /$$__  $$  /$$_____/  /$$_____/
  | $$   | $$ \ $$ \ $$ | $$  \ $$ | $$  \__/ | $$$$$$$$ |  $$$$$$  |  $$$$$$
  | $$   | $$ | $$ | $$ | $$  | $$ | $$       | $$_____/  \____  $$  \____  $$
 /$$$$$$ | $$ | $$ | $$ | $$$$$$$/ | $$       |  $$$$$$$  /$$$$$$$/  /$$$$$$$/
|______/ |__/ |__/ |__/ | $$____/  |__/        \_______/ |_______/  |_______/
                        | $$
                        | $$
                        |__/
 **/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <chrono>
#include <numeric>
#define ll long long

using namespace std;
auto mod = 1e9 + 7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct node {
    int x;
    int y;
    bool operator<(const node& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

void solve() {
    ll n, ans = LLONG_MAX, tmp;
    string s;
    cin >> n >> s;

    // n - 2 operations means that there will be only one pair of digits treated as one number
    for (int idx = 0; idx < n - 1; ++idx) {
        ll two_digits = (s[idx + 1] - '0') + ((s[idx] - '0') * 10);
        tmp = 0;

        for (int i = 0; i < n; ++i) {
            ll curr = s[i] - '0';

            // if it's the two digits number, treat them as one number and increment the loop
            if (i == idx) {
                curr = two_digits;
                i++;
            }

            // if the current digit is zero, we can use only multiplication so the final result is zero
            if (curr == 0) {
                cout << 0 << endl;
                return;
            }

            // if curr == 1, we can just multiply by it so it's ignored
            // we only add it if it's the last item and we did not add anything yet
            if (curr != 1 || (tmp == 0 && i == n - 1)) tmp += curr;
        }

        // minimize the answer
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}