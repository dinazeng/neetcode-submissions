class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist (n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (vector<int> &edge : flights) {
                int u = edge[0];
                int v = edge[1];
                int cost = edge[2];

                if (dist[u] != INT_MAX && temp[v] > dist[u] + cost) {
                    if (i == n - 1) {
                        return -1;
                    }

                    temp[v] = dist[u] + cost;
                }
            }

            dist = temp;
        }

        if (dist[dst] == INT_MAX) {
            return -1;
        }


        return dist[dst];
    }
};
