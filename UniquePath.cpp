class Solution {
public:
    int solve(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(r == 0 and c == 0 and grid[r][c] == 0) return 1;

        if(r < 0 || c < 0) return 0;
        if(grid[r][c] == 1) return 0;

        if(dp[r][c] != -1) return dp[r][c];

        int up = solve(r-1,c,grid,dp);
        int left = solve(r,c-1,grid,dp);

        return dp[r][c] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        return solve(row-1,col-1,obstacleGrid,dp);
    }
};