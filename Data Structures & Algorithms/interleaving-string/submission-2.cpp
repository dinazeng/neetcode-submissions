class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size_1 = s1.length();
        int size_2 = s2.length();

        if (s3.size() != size_1 + size_2) {
            return false;
        }

        vector<vector<bool>> dp (size_1 + 1, vector<bool> (size_2 + 1));
        dp[size_1][size_2] = true;

        for (int i = size_1; i >= 0; i--) {
            for (int j = size_2; j >= 0; j--) {
                if (i < size_1 && s1[i] == s3[i + j] & dp[i + 1][j]) {
                    dp[i][j] = true;
                }
                if (j < size_2 && s2[j] == s3[i + j] & dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[0][0];
    }
};
