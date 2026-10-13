class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj (n);

        for (vector<int> &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited.insert(0);

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();
            for (int neighbour : adj[node]) {
                if (neighbour == parent) continue;
                if (visited.contains(neighbour )) {
                    return false;
                }

                visited.insert(neighbour);
                q.push({neighbour, node});
            }
        }



        return visited.size() == n;
    }
};
