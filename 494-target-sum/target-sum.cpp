class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i =0; i < nums.size(); i++){
            sum += nums[i];
        }
        if ((sum-target) < 0 || (sum-target)%2 !=0) return 0;
        else return isSubsetSum(nums,(sum-target)/2);
        
    }

    int isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));        
        for (int  i = 0; i <= n ; i++) dp[i][0] = 1;        
        for (int i = 1; i <= n ; i++){
            for(int j = 0; j <=sum; j++){
                if (arr[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
        }        
        return dp[n][sum];
    }
};