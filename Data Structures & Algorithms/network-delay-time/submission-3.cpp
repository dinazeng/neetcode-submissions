class Solution {
public:
   int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj (n + 1);
        for (vector<int> e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        int time = 0;

        set<int> visited;
        while (!pq.empty()) {
            auto top = pq.top();
            int u = top.second;
            int distance = top.first;

            pq.pop();

            visited.insert(u);

            if (distance > dist[u]) continue;

            time = max(time, dist[u]);

            for (auto p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return visited.size() == n ? time : -1;
    }
};
