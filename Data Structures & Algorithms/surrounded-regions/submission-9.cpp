class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;

        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') {
                board[r][0] = 'C';
                q.push({r, 0});
            }

            if (board[r][cols - 1] == 'O') {
                board[r][cols - 1] = 'C';
                q.push({r, cols - 1});
            }
        }

        for (int c = 1; c < cols - 1; c++) {
            if (board[0][c] == 'O') {
                board[0][c] = 'C';
                q.push({0, c});
            }

            if (board[rows - 1][c] == 'O') {
                board[rows - 1][c] = 'C';
                q.push({rows - 1, c});
            }
        }

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                if (board[nr][nc] == 'O') {
                    board[nr][nc] = 'C';
                    q.push({nr, nc});
                }
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'C') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
