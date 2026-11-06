class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len_1 = s1.length();
        int len_2 = s2.length();

        if (len_1 + len_2 != s3.length()) {
            return false;
        }

        vector<vector<bool>> dp (len_1 + 1, vector<bool> (len_2 + 1));

        dp[len_1][len_2] = true;

        for (int i = len_1; i >= 0; i--) {
            for (int j = len_2; j >= 0; j--) {
                if (i < len_1 && s1[i] == s3[i + j] && dp[i + 1][j]) {
                    dp[i][j] = true;
                }

                if (j < len_2 && s2[j] == s3[i + j] && dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }
        

        return dp[0][0];
    }
};
