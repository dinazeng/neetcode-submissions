class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);
        vector<int> indegrees(n + 1);

        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegrees[u]++;
            indegrees[v]++;
        }

        queue<int> q; 

        for (int i = 0; i <= n; i++) {
            if (indegrees[i] == 1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            indegrees[node]--;

            for (const auto& nei : adj[node]) {
                indegrees[nei]--;

                if (indegrees[nei] == 1) {
                    q.push(nei);
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];
            if (indegrees[u] == 2 && indegrees[v])
                return {u, v};
        }

        return {};
    }
};
