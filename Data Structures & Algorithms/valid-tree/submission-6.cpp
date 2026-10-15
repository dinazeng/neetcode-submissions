class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);

        for (vector<int> e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> q;
        unordered_set<int> visited;

        q.push({0, -1});
        visited.insert(0);

        while (!q.empty()) {
            int front = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbour : adj[front]) {
                if (neighbour == parent) continue;
                if (visited.contains(neighbour)) {
                    return false;
                }
                visited.insert(neighbour);
                q.push({neighbour, front});
            }
        }

        return visited.size() == n;
    }
};
