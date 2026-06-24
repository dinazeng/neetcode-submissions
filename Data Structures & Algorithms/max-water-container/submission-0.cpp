class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int leftHeight = heights[left];
            int rightHeight = heights[right];
            int area = (right - left) * min(leftHeight, rightHeight);

            maxArea = max(maxArea, area);

            if (leftHeight < rightHeight) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
