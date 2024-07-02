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
unordered_map<ll, ll> parent;

bool dijkstra(const ll& src, const ll& target) {
    for (const auto& node : adj) {
        cost[node.first] = LLONG_MAX;
        for (const auto& neighbor : node.second)
            cost[neighbor.first] = LLONG_MAX;
    }

    if (cost.find(target) == cost.end()) return false;

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
                parent[v] = u;
            }
        }
    }

    return (cost[target] != LLONG_MAX);
}

void print_shortest_path(ll start, ll target) {
    vector<ll> s;
    ll curr = target;
    while (true) {
        if (curr == start) {
            s.push_back(curr);
            break;
        }

        s.push_back(curr);
        curr = parent[curr];
    }

    reverse(s.begin(), s.end());
    for (auto i : s)
        cout << i << " ";

}

void solve() {
    ll n, m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    bool success = dijkstra(1, n);

    if (success) print_shortest_path(1, n);
    else cout << -1;
    cout << endl;
}

int main() {
    fast();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}