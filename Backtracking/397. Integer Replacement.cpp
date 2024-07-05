class Solution {
public:
    long long ans = LLONG_MAX;
    void backtrack(long long n, long long operations) {
        if (n == 1) {
            ans = min(ans, operations);
        } else if (!(n & 1)) {
            backtrack(n / 2, operations + 1);
        } else {
            backtrack(n + 1, operations + 1);
            backtrack(n - 1, operations + 1);
        }
    }

    int integerReplacement(int n) {
        backtrack(n, 0);
        return ans;
    }
};