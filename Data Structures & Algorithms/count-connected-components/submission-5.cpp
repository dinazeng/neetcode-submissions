class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;

        vector<vector<int>> adj(n);
        for (const vector<int> &e : edges) {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }

        
        set<int> visited;

        for (int i = 0; i < n; i++) {
            if (!visited.contains(i)) {
                dfs(visited, adj, i);
                count++;
            }
        }

        return count;
    }

    void dfs (set<int> &visited, vector<vector<int>> &adj, int start) {
        stack<pair<int, int>> st;
        st.push({start, -1});
        visited.insert(start);

        while (!st.empty()) {
            int node = st.top().first;
            int parent = st.top().second;
            st.pop();

            for (const int &c : adj[node]) {
                if (c == parent || visited.contains(c)) continue;

                st.push({c, node});
                visited.insert(c);
            }
        }

    }
};
