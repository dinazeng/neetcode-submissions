class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        if (m + n != s3.size()) {
            return false;
        }

        vector<vector<bool>> dp (m + 1, vector<bool>(n + 1, false));

        dp[m][n] = true;

        for (int r = m; r >= 0; r--) {
            for (int c = n; c >= 0; c--) {
                if (r < m && s1[r] == s3[r + c] && dp[r + 1][c]) {
                    dp[r][c] = true;
                }
                
                if (c < n && s2[c] == s3[r + c] && dp[r][c + 1]) {
                    dp[r][c] = true;
                }
            }
        }
        return dp[0][0];
    }
};
