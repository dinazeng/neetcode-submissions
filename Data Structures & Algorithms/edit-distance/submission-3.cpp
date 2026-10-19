class Solution {
public:
    int minDistance(string word1, string word2) {
        int length_1 = word1.length();
        int length_2 = word2.length();

        vector<vector<int>> dp (length_1 + 1, vector<int> (length_2 + 1));

        for (int i = 0; i <= length_1; i++) {
            dp[i][0] = i;
        }

        for (int i = 0; i <= length_2; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= length_1; i++) {
            for (int j = 1; j <= length_2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
                }
            }
        }


        return dp[length_1][length_2];
    }
};
