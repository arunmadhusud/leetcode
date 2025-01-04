class Solution {
public:
    int minInsertions(string s) {
        string word1 = s;
        std::reverse(s.begin(),s.end());
        string word2 = s;

        int m = word1.size();
        int n = word2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1,0));

        for(int i = 1; i<=m; i++){
            for(int j=1; j<=n;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] =  1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return(word1.size()-dp[m][n]);
        
    }
};