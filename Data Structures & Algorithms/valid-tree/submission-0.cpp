class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);

        for (vector<int> e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        stack<int> st;
        st.push(0);
        visited[0] = true;
        int count = 1;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (int nb : adj[node]) {
                if (!visited[nb]) {
                    visited[nb] = true;
                    count++;
                    st.push(nb);
                }
            }
        }

        return count == n;
    }
};
