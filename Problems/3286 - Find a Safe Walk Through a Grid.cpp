/*
=========================================
LeetCode 3286 - Find a Safe Walk Through a Grid
=========================================

Difficulty :medium 

Pattern    :standard dijsktra 

Time        :

Space       :

Date Solved : 2026-07-02

=========================================
*/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], 0, 0});

        int dir[4][2] = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        while(!pq.empty()){

            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int x = curr[1];
            int y = curr[2];

            if(cost > dist[x][y])
                continue;

            if(x == m-1 && y == n-1)
                return cost < health;

            for(auto &d : dir){

                int nx = x + d[0];
                int ny = y + d[1];

                if(nx<0 || ny<0 || nx>=m || ny>=n)
                    continue;

                int newCost = cost + grid[nx][ny];

                if(newCost < dist[nx][ny]){

                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        } 
        return false;
    }
};
