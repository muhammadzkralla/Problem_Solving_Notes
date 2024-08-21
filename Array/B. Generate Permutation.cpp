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
#define ld long double

using namespace std;
auto mod = 1e9 + 7;
const ll oo = 2e15 + 20;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);

    // generate the sequence 1, n, 2, (n - 1), 3, (n - 2)...
    ll l = 1, r = n;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (flag) {
            v[i] = l++;
            flag = false;
        } else {
            v[i] = r--;
            flag = true;
        }
    }

    // counting the length of the continous sequence in the array from front
    ll first = 1, curr1 = v[0];
    for (ll i = 1; i < n; ++i) {
        if (v[i] == curr1 + 1) {
            first++;
            curr1++;
        }
    }

    // counting the length of the continous sequence in the array from back
    ll second = 1, curr2 = v[n - 1];
    for (ll i = n - 2; i >= 0; --i) {
        if (v[i] == curr2 + 1) {
            second++;
            curr2++;
        }
    }

    // the number of carrige returns equal to n - len of the longest continous seq
    first = n - first;
    second = n - second;

    if (first == second) {
        for (auto i : v) {
            cout << i << " ";
        }

        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}