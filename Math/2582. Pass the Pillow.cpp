class Solution {
public:
    int passThePillow(int n, int time) {
        // time = ( (n - 1) * no.rounds ) + rem
        int rounds = time / (n - 1);
        int rem = time % (n - 1);

        if (rounds & 1) {
            // if rounds are odd, we move rem moves from left to right
            return n - rem;
        } else {
            // if rounds are even, we move rem moves from right to left
            return rem + 1;
        }
    }
};