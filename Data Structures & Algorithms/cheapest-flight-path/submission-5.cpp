class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (const vector<int>& f : flights) {
                int curr_dist = dist[f[0]];
                if (curr_dist == INT_MAX) continue;

                int next_dist = temp[f[1]];
                if (next_dist > curr_dist + f[2]) {
                    temp[f[1]] = curr_dist + f[2];
                    
                }
            }

            dist = temp;
        }

        return dist[dst] != INT_MAX ? dist[dst] : -1;
    }
};
