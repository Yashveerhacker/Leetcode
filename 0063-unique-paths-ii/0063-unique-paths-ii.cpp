class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& grid)
    {
        if(i>=m||j>=n)
        {
            return 0;
        }
        if(obstacleGrid[i][j] == 1)
        {
            return 0;
        }
        if(i==m - 1 && j==n - 1)
        {
            return 1;
        }
        if(grid[i][j]!=-1)
        {
            return grid[i][j];
        }

        int down = solve(i + 1,j,m,n,obstacleGrid,grid);
        int right = solve(i,j + 1,m,n,obstacleGrid,grid);
        grid[i][j] = down + right;
        return grid[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> grid(m, vector<int>(n, -1));
        int ans = solve(0, 0, m, n, obstacleGrid, grid);
        return  ans;
    }
};