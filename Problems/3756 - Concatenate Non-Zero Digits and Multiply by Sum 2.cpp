/*
=========================================
LeetCode 3756 - Concatenate Non-Zero Digits and Multiply by Sum 2
=========================================

Difficulty :medium

Pattern    :string ,prefix sum

Time        :

Space       :

Date Solved : 2026-07-08

=========================================
*/
class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> prefCnt(n + 1, 0);
        vector<long long> prefSum(n + 1, 0);

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefHash(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefCnt[i + 1] = prefCnt[i];
            prefSum[i + 1] = prefSum[i];
            prefHash[i + 1] = prefHash[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                prefCnt[i + 1]++;
                prefSum[i + 1] += d;
                prefHash[i + 1] =
                    (prefHash[i + 1] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sumDigits = prefSum[r + 1] - prefSum[l];

            int before = prefCnt[l];
            int inside = prefCnt[r + 1] - prefCnt[l];

            if (inside == 0) {
                ans.push_back(0);
                continue;
            }

            long long leftHash = prefHash[l];
            long long rightHash = prefHash[r + 1];

            long long x =
                (rightHash -
                 leftHash * pow10[inside] % MOD +
                 MOD) % MOD;

            ans.push_back((x * (sumDigits % MOD)) % MOD);
        }
        return ans;
    }
};