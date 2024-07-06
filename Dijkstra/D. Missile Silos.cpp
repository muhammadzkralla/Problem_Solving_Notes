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
unordered_map<ll, vector<pair<ll, ll>>> dir_adj;
unordered_map<ll, ll> cost;

void dijkstra_pq(const ll& src) {

    // set all costs to infinity as a start
    for (const auto& node : adj) {
        cost[node.first] = LLONG_MAX;
        for (const auto& neighbor : node.second)
            cost[neighbor.first] = LLONG_MAX;
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    cost[src] = 0;
    pq.emplace(cost[src], src);

    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();

        for (auto& edge : adj[u]) {
            ll v = edge.first;
            ll weight = edge.second;

            if (cost[u] + weight < cost[v]) {
                cost[v] = cost[u] + weight;
                pq.emplace(cost[v], v);
            }
        }
    }
}

void solve() {
    ll n, m, s, a, b, w, l, ans = 0;
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        adj[--a].emplace_back(--b, w);
        adj[b].emplace_back(a, w);
        // dir_adj is used to store the edge only once
        dir_adj[a].emplace_back(b, w);
    }

    cin >> l;
    dijkstra_pq(--s);

    // add all the cities that the shortest path between it and the capital is exactly l
    for (int i = 0; i < n; ++i) if (cost[i] == l) ans++;

    // brute force on all the edges
    for (int i = 0; i < n; ++i) {
        for (auto edge : dir_adj[i]) {
            // edge from a -> b with weight : w
            a = i, b = edge.first, w = edge.second;
            // the needed distance from the current edge starting from city a and from city b respectively
            ll first_needed = l - cost[a];
            ll first_spot = w - first_needed;
            ll second_needed = l - cost[b];
            ll second_spot = w - second_needed;

            // if the first spot lies on the edge and is not coincided with the second spot and vice versa, count the spot
            if (first_spot > 0 && first_needed > 0 && first_spot > second_needed) ans++;
            if (second_spot > 0 && second_needed > 0 && second_spot > first_needed) ans++;

            // if the two spots are coincided with each other, count them as the same spot, one spot
            if (first_needed > 0 && second_needed > 0 && first_needed + second_needed == w) ans++;
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