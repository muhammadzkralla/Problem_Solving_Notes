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

void merge(vector<ll>& arr, ll l, ll mid, ll r) {
    deque<ll> dq1, dq2;

    // The first half
    for (ll i = l; i <= mid; ++i)
        dq1.push_back(arr[i]);

    // The second half
    for (ll i = mid + 1; i <= r; ++i)
        dq2.push_back(arr[i]);

    // While both are not empty, compare between the values to decide which to put first
    ll k = l;
    while (!dq1.empty() && !dq2.empty()) {
        if (dq1.front() < dq2.front()) {
            arr[k++] = dq1.front();
            dq1.pop_front();
        } else {
            arr[k++] = dq2.front();
            dq2.pop_front();
        }
    }

    // If there's still some elements in the first half, add them all as there's no elements to compare with
    while (!dq1.empty()) {
        arr[k++] = dq1.front();
        dq1.pop_front();
    }

    // Same with the second half
    while (!dq2.empty()) {
        arr[k++] = dq2.front();
        dq2.pop_front();
    }

}

void merge_sort(vector<ll>& arr, ll l, ll r) { // NOLINT(misc-no-recursion)
    if (l >= r) return;

    ll mid = l + (r - l) / 2;

    // keep splitting the array into halves until they are totally separate and then, merge them in order
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    merge_sort(v, 0, n - 1);

    for (int i = 0; i < n; ++i) cout << v[i] << ((i != n - 1) ? ", " : "\n");
    cout.flush();
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}