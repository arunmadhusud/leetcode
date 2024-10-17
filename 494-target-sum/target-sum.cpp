class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {        

        int total_sum = 0;
        int max_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            total_sum += nums[i];
        }
        if ((total_sum - target) < 0 || (total_sum - target) % 2 != 0) {
            return 0;
        }
        int half_sum = (total_sum - target) / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(half_sum+1, 0));

        for(int i = 0; i <= nums.size(); i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= half_sum; j++) {
            if (nums[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
            }
            }
        }

        return (dp[nums.size()][half_sum]);
    }
};