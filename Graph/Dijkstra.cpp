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

vector<vector<pair<ll, ll>>> adj(6);
vector<ll> cost(6, LLONG_MAX);
vector<ll> parent(6, -1);

void dijkstra(ll src) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    cost[src] = 0;
    pq.emplace(cost[src], src);

    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();

        for (auto &edge : adj[u]) {
            ll v = edge.first;
            ll weight = edge.second;

            if (cost[u] + weight < cost[v]) {
                cost[v] = cost[u] + weight;
                pq.emplace(cost[v], v);
                parent[v] = u;
            }
        }
    }
}

void print_shortest_path(ll start, ll target) {
    string s;
    ll curr = target;
    while (true) {
        if (curr == start) {
            s += to_string(curr);
            break;
        }

        s += to_string(curr) + "->";
        curr = parent[curr];
    }
    cout << "Shortest path from " << start << " to: " << target <<  " :" << endl;
    cout << s << endl;
    cout << "The cost: " << cost[target] << endl;
    cout << "********************" << endl;
}

void solve() {
    adj[0].emplace_back(1, 5);
    adj[0].emplace_back(2, 0);
    adj[1].emplace_back(3, 15);
    adj[1].emplace_back(4, 20);
    adj[2].emplace_back(3, 30);
    adj[2].emplace_back(4, 35);
    adj[3].emplace_back(5, 20);
    adj[4].emplace_back(5, 10);

    dijkstra(0);
    for (int i = 1; i < 6; ++i)
        print_shortest_path(0, i);
}

int main() {
    fast();
    int t = 1;
//    cin >> t;
    while (t--){
        solve();
    }
}