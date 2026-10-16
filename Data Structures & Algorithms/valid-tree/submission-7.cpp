class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj (n);
        vector<int> degrees(n);

        for (vector<int> &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            degrees[e[0]]++;
            degrees[e[1]]++;
        }

        queue<pair<int,int>> q;

        q.push({0, -1});

        set<int> visited;
        while (!q.empty()) {
            int top = q.front().first;
            int parent = q.front().second;
            q.pop();

            if (visited.contains(top)) {
                return false;
            }

            visited.insert(top);

            for (int &nei : adj[top]) {
                if (nei == parent) continue;
                q.push({nei, top});
            }
        }


        return visited.size() == n;
    }
};
