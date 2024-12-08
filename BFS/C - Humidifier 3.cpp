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

const ll mod = 1e9 + 7;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
vector<string> grid;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool valid(ll x, ll y, ll h, ll w) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

ll bfs(ll h, ll w, ll d) {
    map<pair<ll, ll>, bool> visited;
    queue<tuple<ll, ll, ll>> q;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 'H') {
                q.emplace(i, j, 0);
                visited[{i, j}] = true;
            }
        }
    }

    ll count = 0;

    while (!q.empty()) {
        auto [x1, y1, dist] = q.front();
        q.pop();
        count++;

        if (dist == d) continue;

        for (int i = 0; i < 4; ++i) {
            ll x2 = x1 + dx[i], y2 = y1 + dy[i];

            if (valid(x2, y2, h, w) && !visited[{x2, y2}] && grid[x2][y2] != '#') {
                visited[{x2, y2}] = true;
                q.emplace(x2, y2, dist + 1);
            }
        }
    }

    return count;
}

void solve() {
    ll h, w, d;
    cin >> h >> w >> d;
    grid.resize(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    cout << bfs(h, w, d) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
