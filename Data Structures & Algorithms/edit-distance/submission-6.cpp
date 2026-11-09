class Solution {
public:
    int minDistance(string word1, string word2) {
        int len_one = word1.length();
        int len_two = word2.length();

        vector<vector<int>> dp (len_one + 1, vector<int> (len_two + 1));

        for (int i = 1; i <= len_one; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= len_two; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= len_one; i++) {
            char w = word1[i - 1];
            for (int j = 1; j <= len_two; j++) {
                if (w == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }

        return dp[len_one][len_two];
    }
};
