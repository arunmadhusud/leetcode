class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1,0));

        for(int i = 1; i<=m; i++){
            for(int j=1; j<=n;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j] =  1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        

        string substr = "";
        while(m>0 && n>0){
            if(str1[m-1]==str2[n-1]){
                substr += str1[m-1];
                m--;
                n--;
            }
            else if (dp[m-1][n]>dp[m][n-1])
            {   
                substr += str1[m-1];
                m--;
            }
            else {
                substr += str2[n-1];
                n--;
            }
        }

        while (m > 0) {
            substr += str1[m - 1];
            m--;
        }
        while (n > 0) {
            substr += str2[n - 1];
            n--;
        }
        std::reverse(substr.begin(),substr.end());
        return substr;


        
    }
};