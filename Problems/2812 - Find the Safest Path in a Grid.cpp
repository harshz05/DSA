/*
=========================================
LeetCode 2812 - Find the Safest Path in a Grid
=========================================

Difficulty :hard

Pattern    :multi source bfs

Time        :

Space       :

Date Solved : 2026-07-01

=========================================
*/
class Solution {
public:
    vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}};

    int maximumSafenessFactor(vector<vector<int>>& g) {
        int n = g.size();

        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j]){
                    dis[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto [dx, dy] : d){
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                   dis[nx][ny] > dis[x][y] + 1){
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        priority_queue<vector<int>> pq;
        vector<vector<int>> vis(n, vector<int>(n));

        pq.push({dis[0][0], 0, 0});

        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();

            int sf = t[0], x = t[1], y = t[2];

            if(vis[x][y]) continue;
            vis[x][y] = 1;

            if(x == n - 1 && y == n - 1)
                return sf;
            for(auto [dx, dy] : d){
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]){
                    pq.push({min(sf, dis[nx][ny]), nx, ny});
                }
            }
        }
        return 0;
    }
};