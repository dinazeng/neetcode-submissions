class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROW = heights.size();
        int COL = heights[0].size();

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        int PACIFIC = 0;
        int ATLANTIC = 1;

        set<pair<int, int>> atlantic;
        set<pair<int, int>> pacific;

        stack<vector<int>> st;
    
        for (int r = 0; r < ROW; r++) {
            pacific.insert({r, 0});
            st.push({r, 0, PACIFIC});

            atlantic.insert({r, COL - 1});
            st.push({r, COL - 1, ATLANTIC});
        }

        for (int c = 0; c < COL; c++) {
            pacific.insert({0, c});
            st.push({0, c, PACIFIC});

            atlantic.insert({ROW - 1, c});
            st.push({ROW - 1, c, ATLANTIC});
        }

        while (!st.empty()) {
            auto top = st.top();
            int r = top[0];
            int c = top[1];
            int ocean = top[2];

            st.pop();
            
            for (const vector<int> &d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr < ROW && nr >= 0 && nc < COL && nc >= 0 && heights[nr][nc] >= heights[r][c]) {
                    if (ocean == ATLANTIC && !atlantic.contains({nr, nc})) {
                        atlantic.insert({nr, nc});
                        st.push({nr, nc, ocean});

                    } else if (ocean == PACIFIC && !pacific.contains({nr, nc})) {
                        pacific.insert({nr, nc});
                        st.push({nr, nc, ocean});
                    }
                } 
            }
        }

        vector<vector<int>> intersect;

        for (const pair<int, int> &p : pacific) {
            if (atlantic.contains(p)) {
                intersect.push_back({p.first, p.second});
            }
        }

        return intersect;
    }
};
