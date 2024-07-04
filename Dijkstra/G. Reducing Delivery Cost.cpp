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
vector<vector<ll>> dis;

void dijkstra(const ll& src) {

    // set all costs to infinity as a start
    for (const auto& node : adj) {
        cost[node.first] = LLONG_MAX;
        for (const auto& neighbor : node.second)
            cost[neighbor.first] = LLONG_MAX;
    }

    set<pii> nodes;
    cost[src] = 0;
    nodes.insert({cost[src], src});

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
    ll n, m, k, a, b, w;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        adj[--a].emplace_back(--b, w);
        adj[b].emplace_back(a, w);
    }

    vector<pair<ll, ll>> couriers_paths;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        couriers_paths.emplace_back(a - 1, b - 1);
    }

    // in this vector, we will store the cheapest path from each state to the other before removing the cost of one road
    dis = vector<vector<ll>>(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        dijkstra(i);
        // cheapest cost from state i -> j
        for (int j = 0; j < n; ++j)
            dis[i][j] = cost[j];


        // clear the costs to run dijkstra again starting from a different node
        cost.clear();
    }

    ll ans = LLONG_MAX;
    for (int u = 0; u < n; ++u) {
        for (auto edge : adj[u]) {
            ll curr = 0, v = edge.first;
            // assuming path from u -> v is zero
            for (auto path : couriers_paths) {
                a = path.first, b = path.second;
                // minimum cost from the two paths : (a -> u -> v -> b) or (a -> v -> u -> b)
                ll new_path = min(dis[a][u] + dis[v][b], dis[a][v] + dis[u][b]);
                curr += min(dis[a][b], new_path);
            }

            ans = min(ans, curr);
        }
    }

    cout << ans << endl;
}

int main() {
    fast();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}