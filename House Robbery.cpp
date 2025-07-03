class Solution {
public:
    // int solve(int idx,vector<int> &nums, vector<int> &dp){
    //     if(idx == 0) return nums[0];
    //     if(idx < 0) return 0;

    //     if(dp[idx] != -1) return dp[idx];

    //     int pick = nums[idx] + solve(idx-2,nums,dp);

    //     int not_pick = 0 + solve(idx-1,nums,dp);
    //     return dp[idx] = max(pick,not_pick);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1,-1);
        // return solve(n,nums,dp);
        // vector<int> dp(n,0);
        // dp[0] = nums[0];
        int prev1 = nums[0];
        int prev2 = 0;
        int take = 0;
        int ntake = 0;

        for(int i = 1; i < nums.size(); i++){
            take = nums[i];
            if(i > 1) {
                take += prev2;
            }
            ntake = 0 + prev1;

            prev2 = prev1;
            prev1 = max(take,ntake);
        }
        return prev1;
    }
};