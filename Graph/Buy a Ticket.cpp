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

typedef pair<ll, ll> pii;

unordered_map<ll, vector<pair<ll, ll>>> adj;
unordered_map<ll, ll> cost;
vector<ll> a;

void dijkstra() {
    set<pii> nodes;
    // consider the party costs as initial costs and add all of them to the set to process each node
    // and calculate the smallest cost for its neighabours
    for (int i = 0; i < a.size(); ++i) {
        cost[i] = a[i];
        nodes.insert({cost[i], i});
    }

    while (!nodes.empty()) {
        auto p = *nodes.begin();

        ll u = p.second;
        nodes.erase(nodes.begin());

        for (auto& edge : adj[u]) {
            ll v = edge.first;
            ll weight = edge.second;

            if (cost[u] + weight < cost[v]) {
                nodes.erase({cost[v], v});
                cost[v] = cost[u] + weight;
                nodes.insert({cost[v], v});
            }
        }
    }
}

void solve() {
    ll n, m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        // eliminate the effect of the 1-index and modify the weight to include returning back
        adj[u - 1].emplace_back(v - 1, 2 * w);
        adj[v - 1].emplace_back(u - 1, 2 * w);
    }

    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    dijkstra();

    for (int i = 0; i < n; ++i)
        cout << cost[i] << " ";
}

int main() {
    fast();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}