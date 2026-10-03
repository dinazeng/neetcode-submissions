class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        set<vector<int>> pacific;
        set<vector<int>> atlantic;

        vector<vector<string>> visited (row, vector<string>(col, ""));

        stack<pair<vector<int>, string>> st;

        for (int i = 0; i < col; i++) {
            pacific.insert({0, i});
            atlantic.insert({row - 1, i});
            st.push({{0, i}, "p"});
            st.push({{row - 1, i}, "a"});

            visited[0][i] += 'p';
            visited[row - 1][i] += 'a';
        }

        for (int i = 0; i < row; i++) {
            pacific.insert({i, 0});
            atlantic.insert({i, col - 1});
            st.push({{i, 0}, "p"});
            st.push({{i, col - 1}, "a"});

            visited[i][0] += 'p';
            visited[i][col - 1] += 'a';
        }

        while (!st.empty()) {
            int r = st.top().first[0];
            int c = st.top().first[1];
            string o = st.top().second;

            st.pop();

            for (int i = 0; i < 4; i++) {
                int newR = r + dirs[i][0];
                int newC = c + dirs[i][1];
                if (newR < row && newR >= 0 && newC < col && c + newC >= 0) {
                    if (!visited[newR][newC].contains(o) && heights[newR][newC] >= heights[r][c]) {
                        st.push({{newR, newC}, o});
                        visited[newR][newC] += o;
                    }
                }
            }
        }

        vector<vector<int>> both;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (visited[r][c].contains("a") && visited[r][c].contains("p")) {
                    both.push_back({r, c});
                }
            }
        }

        return both;

    }
};
