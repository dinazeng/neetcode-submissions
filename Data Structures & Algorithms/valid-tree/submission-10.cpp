class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for (const vector<int> &e : edges) {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }

        queue<pair<int, int>> q;
        set<int> visited;

        q.push({0, -1});
        visited.insert(0);

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (const int &c : adj[node]) {
                if (c == parent) continue;
                if (visited.contains(c)) return false;

                q.push({c, node});
                visited.insert(c);
            }
        }

        return visited.size() == n;
    }
};
