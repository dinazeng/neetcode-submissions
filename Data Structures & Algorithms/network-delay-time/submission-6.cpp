class Solution {
public:
   int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        unordered_map<int, vector<pair<int, int>>> adj;
        for(vector<int> &t : times) {
            int u = t[0];
            int v = t[1];
            int d = t[2];

            adj[u].push_back({v, d});
        }

        int time = 0;
        set<int> visited;

        pq.push({0, k});
        
        while (!pq.empty()) {
            int dist = pq.top()[0];
            int node = pq.top()[1];
            pq.pop();

            if (visited.count(node)) continue;

            visited.insert(node);

            time = dist;

            if (adj.count(node)) {
                for (const auto &next : adj[node]) {
                    int new_node = next.first;
                    int new_dist = next.second;

                    if (!visited.count(new_node)) {
                        pq.push({dist + new_dist, new_node});
                    }
                }
            }
        }

        return visited.size() == n ? time : -1;
    }
};
