class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        stack<vector<int>> st;

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                st.push({i, 0});
                visited[i][0] = true;
            }

            if (board[i][n - 1] == 'O') {
                st.push({i, n - 1});
                visited[i][n - 1] = true;
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                st.push({0, j});
                visited[0][j] = true;
            }

            if (board[m - 1][j] == 'O') {
                st.push({m - 1, j});
                visited[m - 1][j] = true;    
            }
        }

        while (!st.empty()) {
            int r = st.top()[0];
            int c = st.top()[1];
            
            st.pop();

            for (const auto d : dirs) {
                int newR = r + d[0];
                int newC = c + d[1];

                if (newR < m && newR > 0 && newC < n && newC > 0) {
                    if (board[newR][newC] == 'O' && !visited[newR][newC]){
                        visited[newR][newC] = true;
                        st.push({newR, newC});
                    }
                }
            }

        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!visited[r][c] && board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }

    }
};
