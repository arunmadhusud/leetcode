class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for (int i = 0; i < nums.size(); i++){
            if (i == 0) dp[0] = nums[0];
            else if (i == 1) dp[1] = max(nums[0],nums[1]);
            else dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        int max_v = INT_MIN;
        for (int elem : dp) max_v = max(max_v,elem);
        return max_v;
        
    }
};