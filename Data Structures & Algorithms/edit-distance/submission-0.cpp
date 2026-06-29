class Solution {
public:
    int minDistance(string word1, string word2) {
        int sizeOne = word1.length();
        int sizeTwo = word2.length();
        vector<vector<int>> grid (sizeOne + 1, (vector<int>(sizeTwo + 1, 0)));

        grid[0][0] = 0;

        for (int r = 1; r <= sizeOne; r++) {
            grid[r][0] =  grid[r - 1][0] + 1;
        }

        for (int c = 1; c <= sizeTwo; c++) {
            grid[0][c] =  grid[0][c - 1] + 1;
        }

        for (int r = 1; r <= sizeOne; r++) {
            for (int c = 1; c <= sizeTwo; c++) {
                if (word1[r - 1] == word2[c - 1]) {
                    grid[r][c] = grid[r - 1][c - 1];
                } else {
                    grid[r][c] = min(grid[r - 1][c], grid[r][c - 1]) + 1;
                    grid[r][c] = min(grid[r][c], grid[r - 1][c - 1] + 1);
                }
            }
        }

        return grid[sizeOne][sizeTwo];
    }
};
