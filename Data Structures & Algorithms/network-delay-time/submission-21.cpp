class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        vector<int> dist(n + 1, INT_MAX);

        for (const vector<int>& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});
        dist[k] = 0;
        visited.insert(k);
        int t = 0;
        
        while (!pq.empty()) {
            auto top = pq.top();
            int node = top.second;
            int time = top.first;

            pq.pop();

            if (time > dist[node]) continue;

            t = time;

            for (auto &p : adj[node]) {
                int new_node = p.first;
                int new_time = p.second + time;

                if (new_time < dist[new_node]) {
                    pq.push({new_time, new_node});
                    dist[new_node] = new_time;
                    visited.insert(new_node);
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};
