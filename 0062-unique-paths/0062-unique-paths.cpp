class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>&grid)
    {
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(grid[i][j]!=-1)
        {
            return grid[i][j];
        }

        int down = solve(i+1,j,m,n,grid);
        int right = solve(i,j+1,m,n,grid);

        grid[i][j] = right + down;
        return grid[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,-1));
        int ans = solve(0,0,m,n,grid);

        return ans;
    }
};