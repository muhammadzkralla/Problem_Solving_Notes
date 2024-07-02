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

typedef pair<ll, string> pii;

unordered_map<string, vector<pair<string, ll>>> adj;
unordered_map<string, ll> cost;
unordered_map<string, string> parent;

void dijkstra(const string& src) {

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

        string u = p.second;
        nodes.erase(nodes.begin());

        for (auto& edge : adj[u]) {
            string v = edge.first;
            ll weight = edge.second;

            if (cost[u] + weight < cost[v]) {
                nodes.erase({cost[v], v});
                cost[v] = cost[u] + weight;
                nodes.insert({cost[v], v});
                parent[v] = u;
            }
        }
    }
}

void print_shortest_path(const string& start, const string& target) {
    string path;
    string curr = target;
    while (curr != start) {
        path = curr + (path.empty() ? "" : "->") + path;
        curr = parent[curr];
    }
    path = start + (path.empty() ? "" : "->") + path;
    cout << "Shortest path from " << start << " to " << target << ":\n";
    cout << path << endl;
    cout << "The cost: " << cost[target] << endl;
    cout << "********************" << endl;
}

void solve() {
    adj["Book"].emplace_back("LP", 5);
    adj["Book"].emplace_back("Poster", 0);
    adj["LP"].emplace_back("Bass Guitar", 15);
    adj["LP"].emplace_back("Drums", 20);
    adj["Poster"].emplace_back("Bass Guitar", 30);
    adj["Poster"].emplace_back("Drums", 35);
    adj["Bass Guitar"].emplace_back("Piano", 20);
    adj["Drums"].emplace_back("Piano", 10);

    dijkstra("Book");

    for (const auto& node : adj) 
        if (node.first != "Book") 
            print_shortest_path("Book", node.first);

}

int main() {
    fast();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}