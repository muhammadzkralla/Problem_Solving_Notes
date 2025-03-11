#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), l = 0, ans = 0;
        map<char, int> freq;

        for (int i = 0; i < n; ++i) {
            freq[s[i]]++;

            while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0) {
                ans += n - i;
                freq[s[l++]]--;
            }
        }

        return ans;
    }
};
