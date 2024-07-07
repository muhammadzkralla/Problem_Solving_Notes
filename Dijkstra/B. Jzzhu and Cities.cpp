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

vector<vector<pair<ll, ll>>> adj;
vector<ll> cost;
set<ll> trains;

void dijkstra_pq(const ll& src, const ll& n) {

    priority_queue<pii, vector<pii>, greater<>> pq;
    cost[src] = 0;
    // process all nodes
    for (int i = 1; i <= n; ++i) pq.emplace(cost[i], i);

    while (!pq.empty()) {
        ll curr_u_cost = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        // if the current cost of u is already greater than cost of u do not complete
        if (curr_u_cost > cost[u]) continue;

        for (auto& edge : adj[u]) {
            ll v = edge.first;
            ll weight = edge.second;

            // check if we can reach v in a cheaper way and if it exists and we are using a train for this, remove it
            if (cost[u] + weight < cost[v] || (cost[u] + weight == cost[v] && trains.find(v) != trains.end())) {
                cost[v] = cost[u] + weight;
                // if we are using this train, delete it
                if (trains.find(v) != trains.end())
                    trains.erase(v);

                pq.emplace(cost[v], v);
            }
        }
    }
}

void solve() {
    ll n, m, k, a, b, w;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    cost.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    // set all costs to infinity as a start
    for (int i = 1; i <= n; ++i) {
        cost[i] = LLONG_MAX;
    }

    // use all the trains
    for (int i = 0; i < k; ++i) {
        cin >> b >> w;
        // minimum is important as there can be duplicate trains to the same city with cheaper values like in testcase 2
        cost[b] = min(w, cost[b]);
        if (trains.find(b) == trains.end())
            trains.insert(b);
    }

    dijkstra_pq(1, n);

    // deleted trains = total amount of trains - the remaining trains
    cout << k - trains.size() << endl;
}

int main() {
    fast();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}