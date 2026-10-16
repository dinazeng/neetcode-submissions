class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water = 0;

        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            int curr_water = (r - l) * min(heights[l], heights[r]);
            max_water = max(curr_water, max_water);

            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return max_water;
    }
};
