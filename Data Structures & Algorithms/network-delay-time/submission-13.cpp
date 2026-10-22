class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (vector<int> &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        set<int> visited;
        vector<int> dist (n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int time = 0;

        dist[k] = time;
        pq.push({time, k});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int node = top.second;
            int time_node = top.first;

            if (time_node > dist[node]) continue;
            visited.insert(node);

            time = time_node;

            for (pair<int, int> &neighbour : adj[node]) {
                int next_node = neighbour.first;
                int next_time = time_node + neighbour.second;

                if (dist[next_node] > next_time) {
                    dist[next_node] = next_time;
                    pq.push({next_time, next_node});
                }
            }
        }

        return visited.size() == n ? time : -1;     
    }
};
