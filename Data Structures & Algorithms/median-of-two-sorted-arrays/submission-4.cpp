class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sizeOne = nums1.size();
        int sizeTwo = nums2.size();

        if (sizeOne > sizeTwo) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int total = sizeOne + sizeTwo;
        int half = (sizeOne + sizeTwo) / 2;

        int right = sizeOne;
        int left = 0;

        while (left <= right) {
            int midOne = (left + right) / 2;
            int midTwo = half - midOne;

            int leftA = midOne > 0 ? nums1[midOne - 1] : INT_MIN;
            int rightA = midOne < sizeOne ? nums1[midOne] : INT_MAX;
            int leftB = midTwo > 0 ? nums2[midTwo - 1] : INT_MIN;
            int rightB = midTwo < sizeTwo ? nums2[midTwo] : INT_MAX;

            if (leftA <= rightB && leftB <= rightA) {
                if (total % 2 == 0) {
                    return (max(leftA, leftB) + min (rightA, rightB))/2.0;
                }

                return (double) min(rightA, rightB);
            } else if (leftA > rightB) {
                right = midOne - 1;
            } else {
                left = midOne + 1;
            }
        }

        return -1;
    }
};
