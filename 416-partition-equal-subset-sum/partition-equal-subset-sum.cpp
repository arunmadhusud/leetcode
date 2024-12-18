class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i< nums.size(); i++)
        {
            sum += nums[i];
        }
        if ((sum % 2) !=0) return false;
        else return subsetSum(nums, sum/2);

        
    }
    bool subsetSum(vector<int>& nums, int sum){
        std::vector<std::vector<int>> dp(nums.size()+1,std::vector<int>(sum+1,false));
        for (int i = 0; i < nums.size(); i++){
            dp[i][0] = true;
        }

        for (int i = 1; i <= nums.size(); i++){
            for (int j = 1; j <= sum; j++){
                if (nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }

        return dp[nums.size()][sum];

    }
};