#include <bits/stdc++.h>

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int l = 0, r = 0;

        while (true) {
            if (r > n) break;

            int size = r - l + 1;

            if (size < m) {
                r++;
            } else {
                string sub = haystack.substr(l, size);
                if (sub == needle) return l;
                l++;
            }
        }

        return -1;
    }
};