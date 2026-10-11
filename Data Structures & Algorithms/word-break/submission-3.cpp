class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();

        vector<bool> words_found (size + 1, false);
        words_found[0] = true;

        for (int i = 1; i <= size; i++) {
            for (string word : wordDict) {
                int length = word.length();
                int start = i - length;
                
                if (start >= 0 && s.substr(start, length) == word) {
                    words_found[i] = words_found[i] || words_found[i - length];
                }
            }
        }

        return words_found[size];
    }
};
