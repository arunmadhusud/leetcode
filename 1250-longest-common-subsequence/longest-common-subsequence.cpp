class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        // Initialize the base cases: dp[i][0] = 0 and dp[0][j] = 0
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        return lcs(text1, text2, n, m, dp);
    }

private:
    int lcs(const string& text1, const string& text2, int n, int m, vector<vector<int>>& dp) {
        // If already computed, return the cached result
        if(dp[n][m] != -1) return dp[n][m];
        
        // If last characters match, add 1 to result and recurse for the rest
        if(text1[n-1] == text2[m-1]) {
            dp[n][m] = 1 + lcs(text1, text2, n-1, m-1, dp);
        } else {
            // If characters don't match, take the max of the two possibilities
            dp[n][m] = max(lcs(text1, text2, n-1, m, dp), lcs(text1, text2, n, m-1, dp));
        }
        
        return dp[n][m];
    }
};
