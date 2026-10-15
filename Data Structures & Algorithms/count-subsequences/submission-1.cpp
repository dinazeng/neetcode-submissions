class Solution {
public:
    int numDistinct(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        
        vector<vector<int>> dp (s_size + 1, vector<int> (t_size + 1, 0));
        
        for (int i = 0; i <= s_size; i++) {
            dp[i][t_size] = 1;
        }

        for (int i = s_size - 1; i >= 0; i--) {
            for (int j = t_size - 1; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j];

                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                } 
            }
        }
        

        return dp[0][0];
    }
};
