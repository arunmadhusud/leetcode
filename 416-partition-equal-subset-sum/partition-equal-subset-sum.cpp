// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int half_sum = 0;
//         for(int i = 0; i < nums.size(); i++){
//             half_sum += nums[i];
//         }
//         if(half_sum %  2 != 0) return false;
//         else half_sum = half_sum/2;

//         vector<vector<int>> dp(nums.size()+1, vector<int>(half_sum + 1, 0)); 

//         for(int i = 1; i <=nums.size(); i++){
//             for (int j = 1; j <= half_sum; j++)
//             {
//                 if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
//                 else dp[i][j] = max(nums[i-1]+dp[i-1][j-nums[i-1]],dp[i-1][j] );
//             }
//         }
//         if(dp[nums.size()][half_sum] != half_sum) return false;
//         return true;
//         }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        // Calculate the total sum of the array
        for(int i = 0; i < nums.size(); i++){
            total_sum += nums[i];
        }

        // If the total sum is odd, we cannot partition it into two equal parts
        if(total_sum % 2 != 0) return false;

        int half_sum = total_sum / 2;

        // DP table initialization, using a boolean matrix to track possible sums
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(half_sum + 1, false));

        // Base case: with 0 items, we can only achieve a sum of 0
        for(int i = 0; i <= nums.size(); i++) {
            dp[i][0] = true;
        }

        // DP logic: fill the table
        for(int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= half_sum; j++) {
                if (nums[i-1] > j) {
                    // If current item is greater than the current sum, we can't include it
                    dp[i][j] = dp[i-1][j];
                } else {
                    // Otherwise, check if the sum can be achieved either by:
                    // 1. Not taking the current item (dp[i-1][j]), or
                    // 2. Including the current item (dp[i-1][j - nums[i-1]])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                }
            }
        }

        // The result is whether we can achieve half of the total sum
        return dp[nums.size()][half_sum];
    }
};
