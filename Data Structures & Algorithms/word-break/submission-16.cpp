class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        
        if (len == 0) {
            return true;
        } 
        
        vector<bool> dp (len + 1);
        dp[0] = true;

        for (int i = 0; i < len; i++) {
            if (!dp[i]) continue;

            for (const auto& w : wordDict) {
                int w_len = w.length();
                if (w_len + i > len) continue;

                if (s.substr(i, w_len) == w) {
                    dp[i + w_len] = true; 
                }
            }
        }

        return dp[len];
    }
};
 