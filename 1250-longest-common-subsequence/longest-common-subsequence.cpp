class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1; i<=n; i++)  {
            for(int j=1; j<=m; j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        } 

        int x = n;
        int y = m;
        string lcsStr = "";

        while(m>0 && n>0){
            if(dp[n][m-1] ==dp[n][m]) m=m-1;
            else{
                lcsStr += text2[m-1];
                m = m-1;
                n=n-1;
            }
        }
        reverse(lcsStr.begin(), lcsStr.end());
        cout << "LCS: " << lcsStr << endl;

        return dp[x][y];  
    }   

};