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
//   c a t 
// c 5 1 1 1
// a 4 4 1 1
// a 1 3 1 1
// a 2 2 1 1
// t 1 1 1 1
//   0 0 0 