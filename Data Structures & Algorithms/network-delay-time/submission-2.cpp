class Solution {
public:
    struct myComp {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1];
        }
    };

    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<vector<int>>> adj;
        for (vector<int> e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, myComp> pq;
        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({k, 0});
        set<int> visited;
        int time = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            int u = top[0];
            int d = top[1];
            pq.pop();
            
            if (d > dist[u]) continue;
            visited.insert(u);
            time = d;

            for (auto &p : adj[u]) {
                int v = p[0];
                int w = p[1];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({v, dist[v]});
                }
            }
        }

        return visited.size() == n ? time : -1;
    }
};
