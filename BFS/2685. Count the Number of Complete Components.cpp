#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, vector<int>> adj;
    set<int> visited;

    bool bfs(int root) {
        deque<int> dq;
        dq.push_back(root);
        visited.insert(root);
        vector<int> nodes;

        while (!dq.empty()) {
            int curr = dq.front();
            dq.pop_front();
            nodes.push_back(curr);

            for (auto neighbor : adj[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    dq.push_back(neighbor);
                }
            }
        }

        for (auto node : nodes)
            if (adj[node].size() != nodes.size() - 1)
                return false;
                
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; ++i)
            if (visited.find(i) == visited.end())
                if (bfs(i) || adj.find(i) == adj.end())
                    ans++;

        return ans;
    }
};
