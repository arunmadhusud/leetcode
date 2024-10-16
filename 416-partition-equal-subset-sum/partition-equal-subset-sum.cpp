class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int half_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            half_sum += nums[i];
        }
        if(half_sum %  2 != 0) return false;
        else half_sum = half_sum/2;

        vector<vector<int>> dp(nums.size()+1, vector<int>(half_sum + 1, 0)); 

        for(int i = 1; i <=nums.size(); i++){
            for (int j = 1; j <= half_sum; j++)
            {
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(nums[i-1]+dp[i-1][j-nums[i-1]],dp[i-1][j] );
            }
        }
        if(dp[nums.size()][half_sum] != half_sum) return false;
        return true;
        }
};