class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // Memoization table for the recursion
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
        // Precompute palindrome checks
        std::vector<std::vector<bool>> isPal(n, std::vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                isPal[i][j] = checkPalindrome(s, i, j);
            }
        }
        return mc(s, 0, n - 1, dp, isPal);
    }

    int mc(string& s, int i, int j, std::vector<std::vector<int>>& dp, std::vector<std::vector<bool>>& isPal) {
        if (dp[i][j] != -1) return dp[i][j];
        if (i >= j || isPal[i][j]) return 0; // No cuts needed if already a palindrome

        int minCut = INT_MAX;
        for (int k = i; k < j; k++) {
            if (isPal[i][k]) { // Only make a cut if the left part is a palindrome
                int cuts = 1 + mc(s, k + 1, j, dp, isPal);
                minCut = min(minCut, cuts);
            }
        }

        dp[i][j] = minCut;
        return dp[i][j];
    }

    bool checkPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
