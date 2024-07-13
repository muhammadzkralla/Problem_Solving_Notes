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
    ll n, m, k;
    cin >> n >> m >> k;
    string river;
    cin >> river ;
    ll canJump = m - 1, water = 0, crocodile = 0;

    for (char curr : river) {
        // if the current cell is a log, we can move forward more m - 1 steps
        // if the current cell is water and we can not move any cell further, we count it
        // as we can not reach water cells more than k times
        // if it's not a log or water and we can not move any cell further, there's no possible
        // path without stepping on a crocodile cell
        if (curr == 'L') {
            canJump = m;
        } else if (curr == 'W' && canJump <= 0) {
            water++;
        } else if (canJump <= 0) {
            crocodile++;
        }
        
        canJump--;
    }

    if (water > k) crocodile++;

    if (crocodile != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    fast();
    int t ;
    cin >> t;
    while (t--) {
        solve();
    }
}