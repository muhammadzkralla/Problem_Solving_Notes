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

#define ll long long
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void generateCombinations(const string& charset, string current, int maxLength, string& s, string& result) {
    // Base case: if the current combination length exceeds maxLength, return
    if (current.length() > maxLength) return;

    // If the current combination is not in the string s and it's lexicographically smaller than the current result, update result
    if (!current.empty() && s.find(current) == string::npos) {
        if (current.size() < result.size() || current < result) {
            result = current;
        }
        return;  // Early termination once the first missing combination is found
    }

    // Generate new combinations by adding one character at a time from the charset
    for (char ch : charset) {
        generateCombinations(charset, current + ch, maxLength, s, result);
    }
}

void solve() {
    ll n;
    string s;
    cin >> n >> s;

    string charset = "abcdefghijklmnopqrstuvwxyz";
    string result = "~";

    generateCombinations(charset, "", 3, s, result);

    cout << result << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
