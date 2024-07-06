class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn = INT32_MAX, mx = INT32_MAX;
        for (auto i : nums) {
            // update the minumum number we passed by
            if (i <= mn) {
                mn = i;
            }
            // if the current number is greater than the first minumum and less than the second one 
            else if (i <= mx) {
                mx = i;
            } 
            // if the current number is greater than both the two minumums, we found the triplet
            else {
                return true;
            }
        }

        return false;
    }
};