#include <bits/stdc++.h>

class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(), b.size()), carry = 0;
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0; i < n; ++i) {
            int first = 0, second = 0;
            if (i < a.size()) first = (a[i] - '0');
            if (i < b.size()) second = (b[i] - '0');
            int sum = first + second + carry;
            ans += to_string(sum % 2);
            carry = sum / 2;
        }

        if (carry) ans += "1";
        reverse(ans.begin(), ans.end());

        return ans;
    }
};