class Solution {
public:
    int solve(int row,int col, vector<vector<int>> grid,vector<vector<int>> &dp){
        //base case
        if(row == 0 and col == 0){
            return grid[0][0];
        }

        if(row < 0 || col < 0) return 999;

        if(dp[row][col] != -1) return dp[row][col];

         int up = grid[row][col] + solve(row-1,col,grid,dp);
         int left = grid[row][col] + solve(row,col-1,grid,dp);

        return dp[row][col] = min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};