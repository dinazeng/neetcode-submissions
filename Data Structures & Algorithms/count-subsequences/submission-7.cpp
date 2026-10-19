class Solution {
public:
    int numDistinct(string s, string t) {
        int size_s = s.size();
        int size_t = t.size();

        vector<vector<int>> dp (size_s + 1, vector<int> (size_t + 1));
        for (int i = 0; i <= size_s; i++) {
            dp[i][size_t] = 1;
        }

        for (int j = size_s - 1; j >= 0; j--) {
            for (int k = size_t - 1; k >= 0; k--) {
                dp[j][k] = dp[j + 1][k];
                
                if (s[j] == t[k]) {
                    dp[j][k] += dp[j + 1][k + 1];
                }
            }
        }

        return dp[0][0];
    }
};
