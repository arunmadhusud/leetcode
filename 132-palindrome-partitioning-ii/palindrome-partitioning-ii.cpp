class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        std::vector<std::vector<int>> dp(n,std::vector<int>(n,-1));
        std::vector<std::vector<bool>> isPal(n,std::vector<bool>(n,false));
        for (int i = 0; i< n; i++){
            for (int j = i; j<n; j++){
                if(isPalindrome(s,i,j)) isPal[i][j] = true;
            }
        }
        return mc(s,i,j,dp,isPal);
        
    }
    int mc(string& s, int i, int j, std::vector<std::vector<int>>& dp, std::vector<std::vector<bool>>& isPal){
        if (dp[i][j]!=-1) return dp[i][j];
        if (i>=j || isPal[i][j]) return 0;
        int minCut = INT_MAX;
        int cuts;
        for (int k = i; k < j; k++) {
            if (isPal[i][k]) { // Only make a cut if the left part is a palindrome
                int cuts = 1 + mc(s, k + 1, j, dp, isPal);
                minCut = min(minCut, cuts);
            }
        }
        dp[i][j] = minCut;
        return dp[i][j];

    }

    bool isPalindrome(string& s, int i, int j){
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};