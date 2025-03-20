#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> parent, rank;

    int find(int u) {
        return (parent[u] == u) ? u : find(parent[u]);
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        vector<unsigned int> cost(n, -1);
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto edge : edges) unite(edge[0], edge[1]);

        for (auto edge : edges) {
            int root = find(edge[0]);
            cost[root] &= edge[2];
        }

        for (auto q : query) {
            if (find(q[0]) != find(q[1])) ans.push_back(-1);
            else {
                int root = find(q[0]);
                ans.push_back(cost[root]);
            }
        }

        return ans;
    }
};
