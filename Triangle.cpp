class Solution {
public:
    int solve(int r,int c,int row,int col,vector<vector<int>> &tg,vector<vector<int>> &dp){
        //base case
        if(r == row){
            return tg[r][c];
        }

        if(dp[r][c] != -1){
            return dp[r][c];
        }

        int d = tg[r][c] + solve(r+1,c,row,col,tg,dp);
        int dg = tg[r][c] + solve(r+1,c+1,row,col,tg,dp);

        return dp[r][c] = min(d,dg);
 
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = row;

        vector<vector<int>> dp(row,vector<int>(row,-1));
        return solve(0,0,row-1,col-1,triangle,dp);
    }
};