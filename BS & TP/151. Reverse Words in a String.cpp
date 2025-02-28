#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size(), r = n - 1;

        while (r >= 0) {
            while (r >= 0 && s[r] == ' ') r--;
            if (r < 0) break;

            int l = r;
            while (l >= 0 && s[l] != ' ') l--;

            if (!ans.empty()) ans += " ";
            ans += s.substr(l + 1, r - l);

            r = l - 1;
        }

        return ans;
    }
};
