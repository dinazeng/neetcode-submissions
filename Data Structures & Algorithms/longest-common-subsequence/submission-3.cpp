class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size_1 = text1.size();
        int size_2 = text2.size();

        if (size_1 == 0 || size_2 == 0) {
            return 0;
        }

        vector<vector<int>> dp (size_1 + 1, vector<int> (size_2 + 1));

        for (int i = 0; i < size_1; i++) {
            for (int j = 0; j < size_2; j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                } 
            }
        }


        return dp[size_1][size_2];
    }
};
