class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len_one = text1.length();
        int len_two = text2.length();

        vector<vector<int>> dp (len_one + 1, vector<int> (len_two + 1));

        for (int i = 1; i <= len_one; i++) {
            for (int j = 1; j <= len_two; j++) {
                if (text2[j - 1] == text1[i - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[len_one][len_two];
    }
};
