class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        int min_dist = INT_MAX;
        for (int i = 0; i < size; i++) {
            int xOne = points[i][0];
            int yOne = points[i][1];
            for (int j = i + 1; j < size; j++) {
                int xTwo = points[j][0];
                int yTwo = points[j][1];
                int dist = abs(xOne - xTwo) + abs(yOne - yTwo);
                
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int cost = 0;

        while (visited.size() < size) {
            int dist = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if (visited.count(node)) continue;

            cost += dist;
            visited.insert(node);
            
            for (const auto &neighbour : adj[node]) {
                if (!visited.count(neighbour.second)) {
                    pq.push({neighbour.first, neighbour.second});
                }
            }
        }

        return cost;
    }
};
