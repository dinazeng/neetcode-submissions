class Solution {
public:
    int numDistinct(string s, string t) {
        int len_s = s.length();
        int len_t = t.length();

        vector<vector<int>> dp (len_s + 1, vector<int> (len_t + 1));

        for (int i = 0; i <= len_s; i++) {
            dp[i][len_t] = 1;
        }

        for (int i = len_s - 1; i >= 0; i--) {
            for (int j = len_t - 1; j >=0; j--) {
                dp[i][j] = dp[i + 1][j];

                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};
