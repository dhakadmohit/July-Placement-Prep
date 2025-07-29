class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        vector<int> lastSeen(32, -1); // last index where bit b was seen

        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b) {
                if ((nums[i] >> b) & 1) {
                    lastSeen[b] = i;
                }
            }

            int maxReach = i;
            for (int b = 0; b < 32; ++b) {
                if (lastSeen[b] != -1) {
                    maxReach = max(maxReach, lastSeen[b]);
                }
            }

            result[i] = maxReach - i + 1;
        }

        return result;
    }
};
