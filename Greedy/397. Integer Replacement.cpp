class Solution {
public:

    int integerReplacement(int n) {
        long cast = (long) n;
        long ans = 0;
        while (cast > 1) {
            if (!(cast & 1)) cast /= 2;
            // (n + 1) % 4 = 0 to make sure it can be divided by two more than one time
            // and give an even number. 3 is an edge case
            else if (cast != 3 && (cast + 1) % 4 == 0) cast++;
            else cast--;

            ans++;
        }

        return ans;
    }
};