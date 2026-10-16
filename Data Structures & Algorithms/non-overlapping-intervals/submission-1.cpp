class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort (intervals.begin(), intervals.end());
        int counter = 0;
        int size = intervals.size();
        int end = intervals[0][1];

        for (int i = 1; i < size; i++) {
            int next_start = intervals[i][0];
            if (next_start >= end) {
                end = intervals[i][1];
            } else {
                counter++;
                end = min(end, intervals[i][1]);
            }
        }

        return counter;
    }
};
