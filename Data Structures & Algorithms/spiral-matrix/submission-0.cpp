class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        bool up = false, down = false, left = false, right = true;

        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;

        int curr_r = 0, curr_c = 0;

        vector<int> order;
        while (true) {
            order.push_back(matrix[curr_r][curr_c]);
            matrix[curr_r][curr_c] = INT_MAX;
            if (order.size() == total) break;

            if (right) {
                curr_c++;
                if (curr_c == n || matrix[curr_r][curr_c] == INT_MAX) {
                    curr_c--;
                    curr_r++;
                    right = false;
                    down = true;
                }
            } else if (down) {
                curr_r++;
                if (curr_r == m || matrix[curr_r][curr_c] == INT_MAX) {
                    curr_r--;
                    curr_c--;
                    down = false;
                    left = true;
                }
            } else if (left) {
                curr_c--;
                if (curr_c < 0 || matrix[curr_r][curr_c] == INT_MAX) {
                    curr_c++;
                    curr_r--;
                    left = false;
                    up = true;
                }
            } else {
                curr_r--;
                if (curr_r < 0 || matrix[curr_r][curr_c] == INT_MAX) {
                    curr_r++;
                    curr_c++;
                    up = false;
                    right = true;
                }
            }
        }
        return order;
    }
};