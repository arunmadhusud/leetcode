class Solution {
public:
    bool isSubsequence(string text1, string text2) {
        if(text1==text2) return true;
        int m = text1.size();
        int n = text2.size();
        std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
        for(int i = 1; i<= m; i++){
            for (int j=1; j<=n; j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
            }
        }        
        
        if (text1.size()==dp[m][n]) return true;
        else return false;
        
    }
};