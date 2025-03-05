#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        return (long long) (1 + (4 * ((long long) n * (n - 1) / 2)));
    }
};
