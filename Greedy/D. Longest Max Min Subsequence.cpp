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
#define ld long double

using namespace std;
auto mod = 1e9 + 7;
const ll oo = 2e15 + 20;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<ll> uniq;
    set<ll> done;
    map<ll, ll> last_index;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        uniq.insert(a[i]);
    }

    for (auto i : uniq) {
        last_index[i] = -1;
    }

    for (ll i = n - 1; i >= 0; --i) {
        if (last_index[a[i]] == -1) last_index[a[i]] = i;
    }

    vector<ll> ans = {a[0]};
    done.insert(a[0]);
    for (int i = 1; i < n; ++i) {
        ll curr = a[i];
        ll sz = ans.size() + 1;
        ll k = ans.size();

        // if already in answer, it can't be enhanced anymore
        if (done.find(curr) != done.end()) continue;

        // if the last element in answer can't be added in the future, we can not remove it
        if (last_index[ans[k - 1]] < i) {
            ans.push_back(curr);
            done.insert(curr);
            continue;
        }

        // enhance the answer as possible
        while (k) {
            sz = ans.size() + 1;

            if ((sz & 1)) { // I need max in this place
                if (curr < ans[k - 1] && last_index[ans[k - 1]] > i) { // check last
                    // if curr is less than the last item in answer
                    // and this item can be added in the future
                    // remove this item
                    done.erase(ans[k - 1]);
                    ans.pop_back();
                } else if (k - 2 >= 0 && curr > ans[k - 2]) { // check before last if exists
                    if (last_index[ans[k - 1]] > i && last_index[ans[k - 2]] > i) {
                        // if curr is more than the item before last in answer
                        // and both the last and the item before last in answer can be 
                        // added in the future
                        // remove both
                        done.erase(ans[k - 1]);
                        done.erase(ans[k - 2]);
                        ans.pop_back();
                        ans.pop_back();
                    }
                }
            } else { // I need min in this place
                if (curr > ans[k - 1] && last_index[ans[k - 1]] > i) { // check last
                    // if curr is more than the last item in answer
                    // and this item can be added in the future
                    // remove this item
                    done.erase(ans[k - 1]);
                    ans.pop_back();
                } else if (k - 2 >= 0 && curr < ans[k - 2]) { // check before last if exists
                    if (last_index[ans[k - 1]] > i && last_index[ans[k - 2]] > i) {
                        // if curr is less than the item before last in answer
                        // and both the last and the item before last in answer can be 
                        // added in the future
                        // remove both
                        done.erase(ans[k - 1]);
                        done.erase(ans[k - 2]);
                        ans.pop_back();
                        ans.pop_back();
                    }
                }
            }

            if (k == ans.size()) break; // if I didn't change anything, it can't be more enhanced
            k = ans.size();
        }

        // add curr to the answer after enhancement is done
        done.insert(curr);
        ans.push_back(curr);
    }

    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i << " ";
    }

    cout << endl;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}