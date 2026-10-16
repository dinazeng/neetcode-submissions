class Solution {
public:
    int maxArea(vector<int>& heights) {
        int size = heights.size();
        int max_water = 0;

        int l = 0;
        int r = size - 1;
        int left = heights[0];
        int right = heights[size - 1];

        while (l < r) {
            int curr_water = (r - l) * min(left, right);
            max_water = max(curr_water, max_water);

            if (left < right) {
                l++;
                left = heights[l];
            } else {
                r--;
                right = heights[r];
            }
        }

        return max_water;
    }
};
