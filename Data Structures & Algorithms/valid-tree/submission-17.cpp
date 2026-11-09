class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 1) return true;

        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);
        vector<int> indegrees(n);

        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegrees[u]++;
            indegrees[v]++;
        }

        queue<int> q; 
        int visited = 0;

        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 1) {
                q.push(i);
                visited++;
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (const auto& nei : adj[node]) {
                indegrees[nei]--;

                if (indegrees[nei] == 1) {
                    q.push(nei);
                    visited++;
                }
            }
        }

        return visited == n;
    }
};
