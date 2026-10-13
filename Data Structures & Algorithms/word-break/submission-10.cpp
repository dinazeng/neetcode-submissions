class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();
        int word_size = wordDict.size();
        vector<bool> sol (size + 1, false);
        sol[0] = true;

        for (int i = 1; i <= size; i++) {
            for (int j = 0; j < word_size; j++) {
                int word_length = wordDict[j].length();
                if (i >= word_length && s.substr(i - word_length, word_length) == wordDict[j]) {
                    sol[i] = sol[i - word_length] || sol[i];
                }
            }
        }


        return sol[size];
    }
};
