class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (const auto& f : flights) {
                int curr_dist = dist[f[0]];
                if (curr_dist == INT_MAX) continue;

                int v = f[1];
                int d = f[2];
                if (temp[v] > curr_dist + d) {
                    temp[v] = curr_dist + d;
                }
            }

            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
