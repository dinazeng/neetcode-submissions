class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;

        int l = 0;
        int r = heights.size() - 1;

        int left_height = heights[l];
        int right_height = heights[r];

        while (l < r) {
            int curr_area = min(left_height, right_height) * (r - l);
            max_area = max(max_area, curr_area);
            if (left_height < right_height) {
                l++;
                left_height = heights[l];
            } else {
                r--;
                right_height = heights[r];
            }
        }

        return max_area;
    }
};
