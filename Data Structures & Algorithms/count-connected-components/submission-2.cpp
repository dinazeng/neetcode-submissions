class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<set<int>> adj(n);

        for (vector<int> e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].insert(v);
            adj[v].insert(u);
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                visited[i] = true;

                stack<int> st;
                st.push(i);

                while (!st.empty()) {
                    int u = st.top();
                    st.pop();

                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            st.push(v);
                            visited[v] = true;
                        }
                    }
                }
            }
        }

        return count;
    }
};
