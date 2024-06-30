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

using namespace std;
auto mod = 1000000007;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    // write your code here
    fast();
    long long x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // All possible edges that create a lattice point that is sqrt(5) far from a point.
    vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; ++i) {
        // For each point that is sqrt(5) far than (x1, y1), see if it's
        // also sqrt(5) far than (x2, y2).
        long long x3 = x1 + dx[i], y3 = y1 + dy[i];
        auto dis = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
        if (dis == (sqrt(5))) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
