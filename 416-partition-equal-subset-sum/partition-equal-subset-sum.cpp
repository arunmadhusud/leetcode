class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        if (sum % 2 != 0) return false;
        else return isSubsetSum(nums, sum/2);


        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));        
        for (int  i = 0; i <= n ; i++) dp[i][0] = true;        
        for (int i = 1; i <= n ; i++){
            for(int j = 1; j <=sum; j++){
                if (arr[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }        
        return dp[n][sum];
    }
};