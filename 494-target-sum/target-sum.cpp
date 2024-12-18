class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum  = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int subset_sum = (sum - target) / 2 ;
        if ((sum - target) < 0 || (sum - target) % 2 != 0) {
            return 0;
        }
        return subsetSum(nums, subset_sum);
        
    }
    int subsetSum(vector<int>& nums, int sum){
        std::vector<std::vector<int>> dp(nums.size()+1,std::vector<int>(sum+1,0));
        for (int i = 0; i <= nums.size(); i++){
            dp[i][0] = 1;
        }

        for (int i = 1; i <= nums.size(); i++){
            for (int j = 0; j <= sum; j++){
                if (nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }

        return dp[nums.size()][sum];
    }
};