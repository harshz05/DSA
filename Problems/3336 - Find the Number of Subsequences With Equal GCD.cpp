/*
=========================================
LeetCode 3336 - Find the Number of Subsequences With Equal GCD
=========================================

Difficulty :Hard 
 
Pattern    :DP on states 

Time        :

Space       :

Date Solved : 2026-07-14

=========================================
*/

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {

        const int MAX = 200;
        vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> ndp = dp;
            for (int g1 = 0; g1 <= MAX; g1++) {

                for (int g2 = 0; g2 <= MAX; g2++) {

                    if (dp[g1][g2] == 0)
                        continue;
                    int ways = dp[g1][g2];

                    int ng1 = (g1 == 0) ? x : gcd(g1, x);
                    int ng2 = (g2 == 0) ? x : gcd(g2, x);

                    ndp[ng1][g2] =
                        (ndp[ng1][g2] + ways) % MOD;

                    ndp[g1][ng2] =
                        (ndp[g1][ng2] + ways) % MOD;
                }
            }
            dp.swap(ndp);
        }
        long long ans = 0;
        for (int g = 1; g <= MAX; g++) {
            ans += dp[g][g];
            ans %= MOD;
        }
        return ans;
    }
};