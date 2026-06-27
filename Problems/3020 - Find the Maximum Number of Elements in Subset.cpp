/*
=========================================
LeetCode 3020 - Find the Maximum Number of Elements in Subset
=========================================

Difficulty : Medium 

Pattern    : Hashing 

Time        :

Space       :

Date Solved : 2026-06-27

=========================================
*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }

        for (auto &[x, cnt] : freq) {

            if (x == 1)
                continue;

            long long cur = x;
            int len = 0;

            while (true) {

                auto it = freq.find(cur);

                if (it == freq.end() || it->second < 2)
                    break;

                len += 2;

                if (cur > 1000000000LL)
                    break;

                cur = cur * cur;
            }

            auto it = freq.find(cur);

            if (it != freq.end() && it->second >= 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }
        return ans;
    }
};
