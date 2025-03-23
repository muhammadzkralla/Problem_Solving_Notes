#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    const ll mod = 1e9 + 7;
    typedef pair<ll, ll> pii;
    vector<vector<pair<ll, ll>>> adj;
    vector<ll> cost, cnt;

    void dijkstra_pq(const ll& src) {
        priority_queue<pii, vector<pii>, greater<>> pq;
        cost[src] = 0;
        cnt[src]++;
        pq.emplace(cost[src], src);

        while (!pq.empty()) {
            auto [c, u] = pq.top();
            pq.pop();

            if (c > cost[u]) continue;

            for (auto& edge : adj[u]) {
                auto [v, w] = edge;

                if (cost[u] + w < cost[v]) {
                    cost[v] = cost[u] + w;
                    pq.emplace(cost[v], v);
                    cnt[v] = cnt[u];
                } else if (cost[u] + w == cost[v]) cnt[v] += (cnt[u] % mod);
            }
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        adj.resize(n);
        cost.resize(n, LLONG_MAX);
        cnt.resize(n, 0);
        for (auto v : roads) {
            ll first = v[0], second = v[1], weight = v[2];
            adj[first].emplace_back(second, weight);
            adj[second].emplace_back(first, weight);
        }

        dijkstra_pq(0);

        return (cnt[n - 1] % mod);
    }
};
