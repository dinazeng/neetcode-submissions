class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int water_left = height[left];

        int right = height.size() - 1;
        int water_right = height[right];

        int trapped = 0;

        while (left < right) {
            if (water_left < water_right) {
                trapped += water_left - height[left];
                
                left++;
                water_left = max(water_left, height[left]);
            } else {
                trapped += water_right - height[right];
                
                right--;
                water_right = max(water_right, height[right]);
            }
        }

        return trapped;
    }
};
