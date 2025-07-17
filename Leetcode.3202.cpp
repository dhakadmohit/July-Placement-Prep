class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        // dp[i][j]: maximum length of valid subsequence ending with mod residues (i, j)
        vector<vector<int>> dp(k, vector<int>(k, 0));

        for (int val : nums) {
            int x = val % k;
            // We'll update dp[*][x] based on dp[x][*] from the previous state
            vector<int> old_dp_x = dp[x];  // store old row x from dp
            for (int j = 0; j < k; ++j) {
                // If we pick current element x after one with mod j:
                // new sequence ending with (j, x) extends dp[x][j]
                dp[j][x] = old_dp_x[j] + 1;
                ans = max(ans, dp[j][x]);
            }
        }
        return ans;
    }
};
