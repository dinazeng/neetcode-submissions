class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;

        int left = 0;
        int right = rows;
        int index = -1;

        while (left <= right) {
            int mid = left + (right - left)/2;

            if (target >= matrix[mid][0] && target <= matrix[mid][cols]) {
                index = mid;
                break;
            } else if (target < matrix[mid][0]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (index == -1) {
            return false;
        }

        left = 0;
        right = cols;

        while (left <= right) {
            int mid = left + (right - left)/2;
            int element = matrix[index][mid];

            if (target == element) {
                return true;
            } else if (target < element) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
