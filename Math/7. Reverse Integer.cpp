class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            // get the right-most digit in the number
            int digit = x % 10;
            // check if overflow will happen, but smartly
            if (ans > INT32_MAX / 10 || ans < INT32_MIN / 10) return 0;
            // shift the current number a unit left and add the digit
            ans = ans * 10 + digit;
            // remove the right-most digit
            x /= 10;
        }

        return ans;
    }
};