class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> degrees(n + 1);

        for (vector<int> e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            degrees[e[0]]++;
            degrees[e[1]]++;
        }

        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (degrees[i] == 1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            degrees[node]--;

            for (int neighbour : adj[node]) {
                degrees[neighbour]--;

                if (degrees[neighbour] == 1) {
                    q.push(neighbour);
                }
            }
        }

        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (degrees[u] > 1 && degrees[v] > 1) {
                return {u, v};
            }
        }

        return {};
    }
};
