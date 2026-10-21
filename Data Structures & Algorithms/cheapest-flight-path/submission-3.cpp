class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<int> pq;
        vector<int> dist (n, INT_MAX);
        
        dist[src] = 0;
        pq.push(src);

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (vector<int> &e : flights) {
                int u = e[0];

                if (dist[u] == INT_MAX) continue;

                int v = e[1];
                int w = e[2];

                if (dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }

        return dist[dst] != INT_MAX ? dist[dst] : -1;
    }
};
