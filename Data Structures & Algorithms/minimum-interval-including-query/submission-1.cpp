class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();

        sort(intervals.begin(), intervals.end());

        // (query value, original index)
        vector<pair<int, int>> qs;
        for (int i = 0; i < m; i++) {
            qs.push_back({queries[i], i});
        }
        sort(qs.begin(), qs.end());

        // min-heap of (size, end)
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> heap;

        vector<int> res(m, -1);
        int i = 0;

        for (auto& [q, idx] : qs) {
            // Add all intervals that start at or before q
            while (i < n && intervals[i][0] <= q) {
                heap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }

            // Discard intervals that end before q (useless from now on)
            while (!heap.empty() && heap.top().second < q) {
                heap.pop();
            }

            if (!heap.empty()) {
                res[idx] = heap.top().first;
            }
        }

        return res;
    }
};
