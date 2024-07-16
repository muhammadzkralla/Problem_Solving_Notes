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

ll binaryToInt(const string& binary) {
    ll result = 0;
    for (char bit : binary) {
        result = (result << 1) | (bit - '0');
    }
    return result;
}

string intToBinary(ll n) {
    if (n == 0) return "0";

    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v;
    v.push_back(n);
    string bin = intToBinary(n);
    // this if statement makes sure to handle numbers with only one setted bit to avoid adding zero
    // which is a non-positive integer
    if (count(bin.begin(), bin.end(), '1') != 1) {
        // starting from the least set bit, remove it, add the number to the list, return it back, 
        // and keep moving until the MSB
        for (ll i = bin.size() - 1; i >= 0; --i) {
            if (bin[i] == '1') {
                bin[i] = '0';
                v.push_back(binaryToInt(bin));
                bin[i] = '1';
            }
        }
    }

    reverse(v.begin(), v.end());

    cout << v.size() << endl;
    for (auto i : v) {
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