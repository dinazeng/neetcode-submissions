class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, INT_MAX);

        for (const auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        int time = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({time, k});
        dist[k] = time;
        set<int> visited;
        visited.insert(k);

        while (!pq.empty()) {
            auto front = pq.top();
            pq.pop();

            int dist_node = front.first;
            int node = front.second;

            if (dist_node > dist[node]) continue;

            time = dist_node;

            for (const auto& nei : adj[node]) {
                int neigh_node = nei.first;
                int neigh_dist = nei.second + dist_node;
                
                if (dist[neigh_node] > neigh_dist) {
                    dist[neigh_node] = neigh_dist;
                    pq.push({neigh_dist, neigh_node});
                    visited.insert(neigh_node);
                }
            }
        }

        return visited.size() == n ? time : -1;
    }
};
