class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // int ans = solve(n-1,coins,amount,dp);
        // return (ans >= 1e9) ? -1 : ans;
        vector<vector<int>> dp(n,vector<int> (amount + 1, 0));

        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0) {
            dp[0][i] =   (i / coins[0]);
            }else {
                dp[0][i] = 1e9;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){

                int not_pick = 0 + dp[i-1][j];
                int pick = 1e9;

                if(coins[i] <= j){
                    pick = 1 + dp[i][j-coins[i]];
                }
                dp[i][j] = min(pick,not_pick);
            }
        }

        int ans = dp[n-1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};