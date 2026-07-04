/*
=========================================
LeetCode 2492 - Minimum Score of a Path between Two Cities'
=========================================

Difficulty :medium 

Pattern    :graph theory ,bfs/dfs 

Time        :

Space       :

Date Solved : 2026-07-04

=========================================
*/
class Solution {
public:

vector<bool>vis ;
 vector<vector<pair<int,int>>> adj;
int ans = INT_MAX ;


  void dfs(int node)
    {
        vis[node] = true;
        for(auto [next, wt] : adj[node])
        {
            ans = min(ans, wt);
            if(!vis[next])
                dfs(next);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {

        adj.resize(n + 1);
        vis.assign(n + 1, false);
       
        for( auto &x : roads ) {
            int u = x[0] ;
            int v = x[1] ;
            int w = x[2] ;

            adj[u].push_back({v,w}) ;
            adj[v].push_back({u,w}) ;
        }

        dfs(1) ;
        return ans ;
        
    }
};