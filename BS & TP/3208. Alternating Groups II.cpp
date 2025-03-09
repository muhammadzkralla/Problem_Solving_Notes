#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), ans = 0, l = 0, r = 1;

        while (r < n + k - 1) {
            if (colors[r % n] != colors[(r - 1) % n]) {
                r++;
                if (r - l >= k) {
                    ans++;
                    l++;
                }
            } else {
                l = r++;
            }
        }

        return ans;
    }
};
