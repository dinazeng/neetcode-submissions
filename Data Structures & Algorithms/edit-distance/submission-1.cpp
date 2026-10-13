class Solution {
public:
    int minDistance(string word1, string word2) {
        int size_1 = word1.size();
        int size_2 = word2.size();

        vector<vector<int>> sol (size_1 + 1, vector<int> (size_2 + 1, 0));
        
        for (int i = 0; i <= size_1; i++) {
            sol[i][0] = i;
        }

        for (int i = 1; i <= size_2; i++) {
            sol[0][i] = i;
        }

        for (int i = 1; i <= size_1; i++) {
            for (int j = 1; j <= size_2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    sol[i][j] = sol[i - 1][j - 1];
                } else {
                    sol[i][j] = 1 + min(sol[i - 1][j], sol[i][j - 1]);
                    sol[i][j] = min(sol[i][j], sol[i - 1][j - 1] + 1);
                }
            }
        }

        return sol[size_1][size_2];
    }
};
