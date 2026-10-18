class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int max_left = height[0];
        int max_right = height[size - 1];
        int curr_left = 0; 
        int curr_right = size - 1;

        int volume = 0;

        while (curr_left < curr_right) {
            if (max_left < max_right) {
                curr_left++;
                max_left = max(height[curr_left], max_left);
                volume += max_left - height[curr_left];

            } else {
                curr_right--;
                max_right = max(height[curr_right], max_right);
                volume += max_right - height[curr_right];
            }
        }

        return volume;
    }
};
