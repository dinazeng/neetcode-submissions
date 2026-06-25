class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sizeOne = nums1.size();
        int sizeTwo = nums2.size();

        if (sizeTwo < sizeOne) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int totalSize = sizeOne + sizeTwo;

        int half = (totalSize + 1) / 2;
        int max = sizeOne;
        int min = 0;

        while (min <= max) {
            int midA = (max + min) / 2;
            int midB = half - midA;

            int leftOne = midA > 0 ? nums1[midA - 1] : INT_MIN;
            int rightOne = midA < sizeOne ? nums1[midA] : INT_MAX;
            int leftTwo = midB > 0 ? nums2[midB - 1] : INT_MIN;
            int rightTwo = midB < sizeTwo ? nums2[midB] : INT_MAX;

            if (leftTwo <= rightOne && leftOne <= rightTwo) {
                if (totalSize % 2 != 0) {
                    return std::max(leftOne, leftTwo);
                }

                return (std::max(leftOne, leftTwo) + std::min(rightOne, rightTwo))/2.0;
            } else if (leftOne > rightTwo) {
                max = midA - 1;
            } else {
                min = midA + 1;
            }
        }

        return -1;
    }
};
