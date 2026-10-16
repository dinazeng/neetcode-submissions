class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();

        if (size == 0) {
            return 0;
        }
        
        int solution = 0;
        int left = 0;
        int right = size - 1;

        int left_max = height[left];
        int right_max = height[right];

        while (left < right) {
            if (left_max < right_max) {
                left++;
                left_max = max (left_max, height[left]);
                solution += left_max - height[left];
            } else {
                right--;
                right_max = max(right_max, height[right]);
                solution += right_max - height[right];
            }
        }

        return solution;
    }
};
