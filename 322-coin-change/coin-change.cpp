// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n+1, vector<int>(amount+1, amount+1)); // Initialize with a large number
        
//         for(int i = 0; i <= n; i++) {
//             dp[i][0] = 0;
//         }

//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j <= amount; j++) {
//                 if(coins[i-1] > j) {
//                     dp[i][j] = dp[i-1][j]; 
//                 } else {
//                     dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]); 
//                 }
//             }
//         }

//         return dp[n][amount] > amount ? -1 : dp[n][amount];
//     }
// };


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;

        for(int i= 1; i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(coins[i-1]<=j) dp[j] = min(dp[j],1+dp[j-coins[i-1]]);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];

    }
};
