#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<long> v;
        for (int i = 0; i < 16; ++i) v.push_back((long) pow(3, i));
        reverse(v.begin(), v.end());
        for (int i : v) {
            if (i <= n) n -= i;
            if (n == 0) return true;
            if (n < 0) return false;
        }

        return false;
    }
};
