#include <bits/stdc++.h>
class Solution {
public:

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size(), m = g.size(), j = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // the minimum item in s can only take the minimum item in g
        // that satisfies the condition s[i] >= g[j] and the 
        // answer will be the number of taken items from g
        for (int i = 0; i < n && j < m; ++i) {
            if (s[i] >= g[j]) {
                j++;
            }
        }

        return j;
    }
};