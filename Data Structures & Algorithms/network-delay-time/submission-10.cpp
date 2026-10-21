class Solution {
public:
   int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, int> visited;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<pair<int, int>>> adj(n + 1);
        for(vector<int> &t : times) {
            int u = t[0];
            int v = t[1];
            int d = t[2];

            adj[u].push_back({v, d});
        }

        pq.push({0, k});
        visited[k] = 0;

        while (!pq.empty()) {
            int dist = pq.top()[0];
            int node = pq.top()[1];
            pq.pop();

            for (pair<int, int> &p: adj[node]) {
                int neighbour = p.first;
                int dist = p.second;

                if (!visited.contains(neighbour) || visited[neighbour] > dist + visited[node]) {
                    visited[neighbour] = dist + visited[node];
                    pq.push({dist + visited[node], neighbour});
                }
            }
        }

        if (visited.size() != n) {
            return -1;
        }

        int time = 0;
        auto it = visited.begin();
        while (it != visited.end()) {
            time = max(time, it->second);
            it++;
        }
       
        return time;
    }
};
