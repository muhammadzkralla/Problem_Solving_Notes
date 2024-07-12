class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        // a ^ a = 0 and a ^ 0 = a
        for (auto i : nums) a ^= i;
        return a;
    }
};