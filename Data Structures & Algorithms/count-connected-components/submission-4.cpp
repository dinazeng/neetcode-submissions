class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        unordered_set<int> seen;

        vector<set<int>> adj(n);

        for (vector <int> &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].insert(v);
            adj[v].insert(u);
        }

        for (int i = 0; i < n; i++) {
            if (!seen.contains(i)) {
                count++;
                seen.insert(i);
                dfs(seen, adj, i);
            }
        }

        return count;
    }

    void dfs(unordered_set<int> &seen, vector<set<int>> &adj, int i) {
        stack<int> st;
        st.push(i);

        while (!st.empty()) {
            int top = st.top();
            st.pop();

            for (int nei : adj[top]) {
                if (!seen.contains(nei)) {
                    seen.insert(nei);
                    st.push(nei);
                }
            }
        }
    }
};
