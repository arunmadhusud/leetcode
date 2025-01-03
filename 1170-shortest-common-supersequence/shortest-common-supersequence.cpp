class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // Compute the LCS DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Construct the SCS
        string scs = "";
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs += str1[i - 1];
                i--;
            } else {
                scs += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters
        while (i > 0) {
            scs += str1[i - 1];
            i--;
        }
        while (j > 0) {
            scs += str2[j - 1];
            j--;
        }

        // Reverse the result since it's built backward
        reverse(scs.begin(), scs.end());
        return scs;
    }
};
