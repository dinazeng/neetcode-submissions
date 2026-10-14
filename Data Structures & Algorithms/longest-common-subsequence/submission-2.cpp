class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size_1 = text1.size();
        int size_2 = text2.size();

        vector<vector<int>> lcs (size_1 + 1, vector<int> (size_2 + 1, 0));
        for (int i = 1; i <= size_1; i++) {
            for (int j = 1; j <= size_2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        return lcs[size_1][size_2];
    }
};
