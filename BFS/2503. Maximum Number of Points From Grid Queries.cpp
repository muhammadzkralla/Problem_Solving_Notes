#include <bits/stdc++.h>
using namespace std;

// create edges on the fly
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// pq of {cost, pos} where pos is the {x, y} coordinates of the cell
typedef pair<int, pair<int, int>> pii;

class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<bool>> visited;
    priority_queue<pii, vector<pii>, greater<>> pq;
    
    void bfs(int val, int &cnt) {

        // stop the BFS if the cost of the first item in the pq is less than the current query value
        while (!pq.empty() && pq.top().first < val) {
            auto [cost, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            // we are sure that the cost is less than the current query value so increment cnt anyways
            cnt++;

            // process the next edges
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < adj.size() && ny >= 0 && ny < adj[0].size() && !visited[nx][ny]) {
                    pq.push({adj[nx][ny], {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> ans(queries.size());
        adj = grid;
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        // sort the queries array while keeping track of the indices
        vector<pair<int, int>> sorted;
        for (int i = 0; i < queries.size(); i++)
            sorted.push_back({queries[i], i});
        
        sort(sorted.begin(), sorted.end());

        // push the first cell in the grid to the pq to initiate the BFS
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        // since we are processing the queries from the min to the max one, paths that are valid to smaller nodes
        // are also valid to the bigger nodes, so we initalize cnt with zero and increment it as we go
        int cnt = 0;
        for (auto [val, idx] : sorted) {
            bfs(val, cnt);
            ans[idx] = cnt;
        }

        return ans;
    }
};
