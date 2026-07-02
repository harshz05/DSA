/*
=========================================
LeetCode 1631 - Path with Minimum Effort
=========================================

Difficulty :medium 

Pattern    :modified dijsktra, heap 

Time        :

Space       :

Date Solved : 2026-07-02

=========================================
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        effort[0][0] = 0;

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({0, 0, 0});

        vector<pair<int, int>> dir = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int currEffort = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (currEffort > effort[x][y])
                continue;

            if (x == m - 1 && y == n - 1)
                return currEffort;

            for (auto &[dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int edge = abs(heights[x][y] - heights[nx][ny]);

                int newEffort = max(currEffort, edge);
                if (newEffort < effort[nx][ny]) {

                    effort[nx][ny] = newEffort;

                    pq.push({newEffort, nx, ny});
                }
            }
        }
        return 0;
    }
};