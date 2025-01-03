class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
        for(int i = 1; i<= m; i++){
            for (int j=1; j<=n; j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
            }
        }        
        return dp[m][n];
        
        
    }

    int lcs(string text1, string text2,int m,int n,std::vector<std::vector<int>>& dp ){        
        if (m==0 || n==0) return 0;
        if (dp[m][n]!=-1) return dp[m][n];
        else if (text1[m-1]==text2[n-1]) dp[m][n] = 1 + lcs(text1, text2,m-1,n-1,dp);
        else dp[m][n] = max(lcs(text1, text2,m-1,n,dp),lcs(text1, text2,m,n-1,dp));
        return dp[m][n];
    }
};