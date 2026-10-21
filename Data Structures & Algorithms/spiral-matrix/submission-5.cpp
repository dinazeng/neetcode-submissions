class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        bool up = false, down = false, left = false, right = true;

        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;

        int curr_r = 0, curr_c = 0, d = 0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> order;
        for (int i = 0; i < total; i++) {
            order.push_back(matrix[curr_r][curr_c]);
            matrix[curr_r][curr_c] = INT_MAX;

            int nr = curr_r + dir[d][0], nc = curr_c + dir[d][1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || matrix[nr][nc] == INT_MAX) {
                d = (d + 1) % 4;
                nr = curr_r + dir[d][0];
                nc = curr_c + dir[d][1];
            }
            curr_r = nr;
            curr_c = nc;
        }
        return order;
    }
};