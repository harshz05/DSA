/*
=========================================
LeetCode 3532 - Path Existence Queries in a Graph 1
=========================================

Difficulty :medium

Pattern    :

Time        :

Space       :

Date Solved : 2026-07-09

=========================================
*/
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> comp(n);
        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff)
                comp[i] = comp[i - 1];
            else
                comp[i] = comp[i - 1] + 1;
        }
        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }

        return ans;
    }
};