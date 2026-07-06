/*
=========================================
LeetCode 1288 - Remove Covered Intervals
=========================================

Difficulty :medium 

Pattern    :sorting , greedy 

Time        :

Space       :

Date Solved : 2026-07-06

=========================================
*/


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];  
                return a[0] < b[0];
            });
        int removed = 0;
        int maxRight = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][1] <= maxRight)
                removed++;
            else
                maxRight = intervals[i][1];
        }
        return intervals.size() - removed;
    }
};

