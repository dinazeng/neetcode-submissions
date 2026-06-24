class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> heap;

        for (vector<int> &p : points) {
            int x = p[0];
            int y = p[1];

            int dist = x*x + y*y; 
            
           heap.push({dist, {x, y}});

            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<vector<int>> results(k);
        for (int i = 0; i < k; i++) {
            results[i] = heap.top().second;
            heap.pop();
        }

        return results;
    }
};
