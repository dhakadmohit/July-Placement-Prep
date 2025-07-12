class Solution {
public:
    long long solve(long long idx, long long amt, vector<long long> &coins,vector<vector<long long>> &dp){

        if(idx == 0 ){
            if(amt % coins[0] == 0){
                return 1;
            }
            return 0;
        }

        if(dp[idx][amt] != -1) return dp[idx][amt];

        long long not_pick = solve(idx-1,amt,coins,dp);
        long long pick = 0;
        if(coins[idx] <= amt){
            pick = solve(idx,amt-coins[idx],coins,dp);
        }
        return dp[idx][amt] = pick + not_pick;
    }
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));

        vector<vector<long long>> dp(coins.size(),vector<long long>(amount+1,0));

        for(long long i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = 1;
            }
        }

        for(long long i = 1; i < coins.size(); i++){
            for(long long j = 0; j <= amount; j++){
                
                long long not_pick = dp[i-1][j];
                long long pick = (coins[i] <= j) ? dp[i][j - coins[i]] : 0;
                dp[i][j] = pick + not_pick;
            }
        }

        // return solve(coins.size()-1, amount,coins,dp);
        return dp[coins.size()-1][amount];
    }
};