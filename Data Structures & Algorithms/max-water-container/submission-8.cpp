class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size() - 1;

        int max_area = 0;

        while (start < end) {
            int area = min(heights[start], heights[end]) * (end - start);
            max_area = max(max_area, area);

            if (heights[start] < heights[end]) {
                start++;
            } else {
                end--;
            }
        }

        return max_area;
    }
};
