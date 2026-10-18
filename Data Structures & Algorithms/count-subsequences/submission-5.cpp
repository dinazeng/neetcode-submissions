class Solution {
public:
    int numDistinct(string s, string t) {
        int size_s = s.size();
        int size_t = t.size();

        vector<vector<int>> dp (size_s + 1, vector<int> (size_t + 1));
        for (int k = 0; k <= size_s; k++) {
            dp[k][size_t] = 1;
        }

        for (int i = size_s - 1; i >= 0; i--) {
            for (int j = size_t - 1; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j];
                
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }
        
        return dp[0][0];
    }
};
