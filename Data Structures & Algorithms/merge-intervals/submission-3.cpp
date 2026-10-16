class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = res.back();

            if (intervals[i][0] <= last[1]) {
                // Overlaps or touches the last merged interval: extend it
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // Gap: start a new interval
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
