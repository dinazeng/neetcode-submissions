class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (vector<int> e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                visited[i] = true;

                stack<int> st;
                st.push(i);
                while (!st.empty()) {
                    int node = st.top();
                    st.pop();

                    for (int neighbour : adj[node]) {
                        if (!visited[neighbour]) {
                            st.push(neighbour);
                            visited[neighbour] = true;
                        }
                    }

                }
            }
        }

        return count;
    }
};
