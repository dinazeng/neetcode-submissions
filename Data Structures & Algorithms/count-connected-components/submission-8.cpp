class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        set<int> visited;
        vector<vector<int>> adj(n);

        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited.contains(i)) {
                components++;
                dfs(visited, adj, i);
            }
        }

        return components;
    }

    void dfs(set<int>& visited, vector<vector<int>>& adj, int i) {
        queue<int> q;
        q.push(i);
        visited.insert(i);

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            for (const auto& nei : adj[front]) {
                if (!visited.contains(nei)) {
                    visited.insert(nei);
                    q.push(nei);
                }
            }
        }
    }
};
