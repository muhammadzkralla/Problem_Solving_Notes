/**
     /$$$$$$$$
    |_____ $$
         /$$/
        /$$/
       /$$/
      /$$/
     /$$$$$$$$
    |________/
 **/

#include <bits/stdc++.h>
#include <climits>

#define ll long long
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<vector<pair<ll, ll>>> adj;
vector<bool> visited;
vector<ll> x;

void dfs(ll root) {
    visited[root] = true;

    for (auto &[v, w] : adj[root]) {
        if (!visited[v]) {
            x[v] = x[root] + w;
            dfs(v);
        }
    }
}

void solve() {
    ll n, m, u, v, w;
    cin >> n >> m;

    adj.resize(n + 1);
    x.resize(n + 1, 0);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, -w);
    }

    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            dfs(i);
    
    for (int i = 1; i <= n; ++i) cout << x[i] << " ";
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
