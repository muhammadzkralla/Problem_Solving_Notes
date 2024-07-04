class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> mp;
        mp.emplace_back(1000, "M");
        mp.emplace_back(900, "CM");
        mp.emplace_back(500, "D");
        mp.emplace_back(400, "CD");
        mp.emplace_back(100, "C");
        mp.emplace_back(90, "XC");
        mp.emplace_back(50, "L");
        mp.emplace_back(40, "XL");
        mp.emplace_back(10, "X");
        mp.emplace_back(9, "IX");
        mp.emplace_back(5, "V");
        mp.emplace_back(4, "IV");
        mp.emplace_back(1, "I");

        string ans;
        vector<int> parts;
        int mul = 1;

        // split the num into thousands, hundreds, tens, and units
        while (num > 0) {
            int digit = num % 10;
            if (digit != 0)
                parts.push_back(digit * mul);

            num /= 10;
            mul *= 10;
        }

        // we will process the larger parts first
        reverse(parts.begin(), parts.end());

        // for each part, we iterate over the mp and start calculating the roman string
        for (auto part : parts) {
            for (const auto& literal : mp) {
                while (part >= literal.first) {
                    part -= literal.first;
                    ans += literal.second;
                }
            }
        }

        return ans;
    }
};