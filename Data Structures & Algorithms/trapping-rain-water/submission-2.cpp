class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int max_left = height[l];
        int max_right = height[r];

        int sum = 0;

        while (l < r) {
            if (max_left < max_right) {
                sum += max_left - height[l];
                l++;

                max_left = max(height[l], max_left);

            } else {
                sum += max_right - height[r];
                r--;

                max_right = max(height[r], max_right);
            }
        }

        return sum;
    }
};
