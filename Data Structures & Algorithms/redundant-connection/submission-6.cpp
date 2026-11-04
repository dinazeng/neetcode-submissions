class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1);
        for (const vector<int> &e : edges) {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);

            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            indegree[node] = 0;

            for (const int &c : adj[node]) {
                indegree[c]--;
                if (indegree[c] == 1) {
                    q.push(c);
                }
            }
        }

        for (int e = edges.size() - 1; e >= 0; e--) {
            if (indegree[edges[e][0]] > 1 && indegree[edges[e][1]] > 1) {
                return {edges[e][0], edges[e][1]};
            }
        }

        return {};
    }
};
