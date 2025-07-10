class Solution {
public:
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
    }

    if(sum % 2 != 0) return false;

    sum = (sum / 2);

    vector<vector<int>> dp(n,vector<int>(sum + 1,false));

    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }

    if (nums[0] <= sum) dp[0][nums[0]] = true;

    for(int j = 1; j < n; j++){
        for(int target = 1; target <= sum; target++){
            bool notpick = dp[j-1][target];
            bool pick = false;
            if(target >= nums[j]){
            pick =  dp[j-1][target-nums[j]];
            }
            dp[j][target] = (pick || notpick);
        }
    }
    return dp[n-1][sum];
}
};