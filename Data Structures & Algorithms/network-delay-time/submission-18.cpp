class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, INT_MAX);

        for (const vector<int> &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        visited.insert(k);
        pq.push({0, k});

        int t = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int time = top.first;
            int node = top.second;
            
            if (time > dist[node]) continue;

            visited.insert(node);

            t = time;

            for (const auto& [next, w] : adj[node]) {
                if (time + w < dist[next]) {
                    dist[next] = time + w;
                    pq.push({dist[next], next});
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};
