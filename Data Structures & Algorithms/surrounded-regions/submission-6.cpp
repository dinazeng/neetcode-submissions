class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROW = board.size();
        int COL = board[0].size();

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;

        for (int r = 0; r < ROW; r++) {
            if (board[r][0] == 'O') {
                q.push({r, 0});
                board[r][0] = 'C';
            }

            if (board[r][COL - 1] == 'O') {
                q.push({r, COL - 1});
                board[r][COL - 1] = 'C';
            }
        }

        for (int c = 0; c < COL; c++) {
            if (board[0][c] == 'O') {
                q.push({0, c});
                board[0][c] = 'C';
            } 

            if (board[ROW - 1][c] == 'O') {
                q.push({ROW - 1, c});
                board[ROW - 1][c] = 'C';
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            int r = front.first;
            int c = front.second;

            q.pop();

            for (const vector<int> &d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < ROW && nc >= 0 && nc < COL && board[nr][nc] == 'O') {
                    board[nr][nc] = 'C';
                    q.push({nr, nc}); 
                }
            }
        }

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (board[r][c] == 'C') {
                    board[r][c] = 'O';
                } else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
