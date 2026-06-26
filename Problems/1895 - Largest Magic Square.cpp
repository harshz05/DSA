/*
=========================================
LeetCode 1895 - Largest Magic Square
=========================================

Difficulty :

Pattern    :

Time        :

Space       :

Date Solved : 2026-06-27

=========================================
*/

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        auto isMagic = [&](int r,int c,int len)->bool
        {
            int target = row[r][c + len] - row[r][c];

            for(int i=r;i<r+len;i++)
            {
                int cur = row[i][c + len] - row[i][c];
                if(cur != target) return false;
            }
            for(int j=c;j<c+len;j++)
            {
                int cur = col[r + len][j] - col[r][j];
                if(cur != target) return false;
            }

            int d1 = 0;
            int d2 = 0;

            for(int k=0;k<len;k++)
            {
                d1 += grid[r+k][c+k];
                d2 += grid[r+k][c+len-1-k];
            }

            return d1 == target && d2 == target;
        };
        for(int len=min(m,n); len>=1; len--)
        {
            for(int r=0;r+len<=m;r++)
            {
                for(int c=0;c+len<=n;c++)
                {
                    if(isMagic(r,c,len))
                        return len;
                }
            }
        }
        return 1;
    }
};
