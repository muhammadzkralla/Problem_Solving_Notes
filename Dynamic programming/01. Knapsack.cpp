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
    ll capacity = 4, n = 3;
    vector<ll> weights = {1, 3, 4};
    vector<ll> prices = {1500, 2000, 3000};
    vector<vector<ll>> dp(n + 1, vector<ll>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) { // Iterate over each item
        for (int j = 0; j <= capacity; ++j) { // Iterate over each weight capacity
            // If the current item can fit in the knapsack
            if (weights[i - 1] <= j) {
                // Decide whether to include the item or not
                dp[i][j] = max(
                    dp[i - 1][j], // Value without including the current item
                    dp[i - 1][j - weights[i - 1]] + prices[i - 1] // Value including the current item
                 ); 
            } else {
                // If the current item cannot fit, carry forward the previous value
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][capacity];
}

int main() {
    fast();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}