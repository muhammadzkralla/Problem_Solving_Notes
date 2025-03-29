#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int mod = 1e9 + 7;

    long long modPow(long long base, int exponent) {
        long long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
    }

    int countPrimes(int n) {
        set<long long> primeFactors;

        while (n % 2 == 0) {
            primeFactors.insert(2);
            n /= 2;
        }

        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                primeFactors.insert(i);
                n /= i;
            }
        }

        if (n > 1) primeFactors.insert(n);

        return primeFactors.size();
    }

    vector<long long> nextGreaterElement(vector<long long>& nums) {
        int n = nums.size();
        vector<long long> result(n, n);
        stack<long long> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                result[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        return result;
    }

    vector<long long> prevGreaterElement(vector<long long>& nums) {
        int n = nums.size();
        vector<long long> result(n, -1);
        stack<long long> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(i);
        }

        return result;
    }

    int maximumScore(vector<int>& nums, int k) {
        long long score = 1;
        long long n = nums.size();
        vector<long long> s(n), left(n), right(n), cnt(n);
        for (int i = 0; i < n; ++i) s[i] = countPrimes(nums[i]);
        left = prevGreaterElement(s);
        right = nextGreaterElement(s);
        for (int i = 0; i < n; ++i) cnt[i] = (i - left[i]) * (right[i] - i);

        vector<pair<long long, long long>> sorted;
        for (int i = 0; i < n; i++)
            sorted.push_back({nums[i], i});
        
        sort(sorted.rbegin(), sorted.rend());

        for (auto [num, idx] : sorted) {
            long long ops = min((long long) k, cnt[idx]);
            k -= ops;
            score = (score * modPow(num, ops)) % mod;
        }

        return score % mod;
    }
};
