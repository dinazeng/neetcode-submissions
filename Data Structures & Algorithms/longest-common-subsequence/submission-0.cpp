class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int sizeOne = text1.length();
        int sizeTwo = text2.length();

        vector<vector<int>> sol (sizeOne + 1, vector<int>(text2.length() + 1, 0));

        for (int r = 1; r < sizeOne + 1; r++) {
            for (int c = 1; c < sizeTwo + 1; c++) {
                if (text1[r - 1] == text2[c - 1]) {
                    sol[r][c] = 1 + sol[r - 1][c - 1];
                } else {
                    sol[r][c] = max(sol[r - 1][c], sol[r][c - 1]);
                }
            }
        }


        return sol[sizeOne][sizeTwo];
    }
};
