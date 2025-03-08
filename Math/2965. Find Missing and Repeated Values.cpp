#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size(), sum = 0, sqrSum = 0, total = n * n;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long curr = grid[i][j];
                sum += curr;
                sqrSum += (curr * curr);
            }
        }

        long long sumDiff = sum - total * (total + 1) / 2;
        long long sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;

        int x = (sqrDiff / sumDiff + sumDiff) / 2;
        int y = (sqrDiff / sumDiff - sumDiff) / 2;

        return {x, y};
    }
};
