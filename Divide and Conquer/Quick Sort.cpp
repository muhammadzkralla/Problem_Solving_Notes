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

ll partition(vector<ll> &arr, ll l, ll r) {
    ll pivot = arr[r];
    ll smaller = l - 1;

    for (ll i = l; i < r; ++i)
        if (arr[i] <= pivot)
            swap(arr[++smaller], arr[i]);

    swap(arr[++smaller], arr[r]);
    return smaller;
}

void quick_sort(vector<ll> &arr, ll l, ll r) { // NOLINT(misc-no-recursion)
    if (l >= r) return;

    ll pi = partition(arr, l, r); // now, item at pi is at the correct index after sorting
    quick_sort(arr, l, pi - 1); // call quick_sort recursively for items before it
    quick_sort(arr, pi + 1, r); // call quick_sort recursively for items after it
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    quick_sort(v, 0, n - 1);

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