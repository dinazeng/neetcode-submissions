class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size();
        int size_2 = nums2.size();

        if (size_1 > size_2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0;
        int right = size_1;
        int half = (size_1 + size_2) / 2;

        while (left <= right) {
            int mid_left = (right + left) / 2;
            int mid_right = half - mid_left;

            int left_one = mid_left > 0 ? nums1[mid_left - 1] : INT_MIN;
            int right_one = mid_left < size_1 ? nums1[mid_left] : INT_MAX;
            int left_two = mid_right > 0 ? nums2[mid_right - 1] : INT_MIN;
            int right_two = mid_right < size_2 ? nums2[mid_right] : INT_MAX;

            if (left_one <= right_two && left_two <= right_one) {
                if ((size_1 + size_2) % 2 == 0) {
                    return (max(left_one, left_two) + min(right_one, right_two)) / 2.0;
                }

                return (double) min(right_one, right_two);
            } else if (left_one > right_two) {
                right = mid_left - 1;
            } else {
                left = mid_left + 1;
            }
        }

        return -1.0;
    }
};
