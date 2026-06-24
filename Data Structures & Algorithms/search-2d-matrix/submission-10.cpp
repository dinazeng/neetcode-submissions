class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int matrix_size = matrix[0].size() - 1;
        int min = 0;
        int max = matrix.size() - 1;
        int index = 0;

        while (min <= max) {
            index = (min + max) / 2;

            if (matrix[index][0] <= target && matrix[index][matrix_size] >= target) {
                break;
            } else if (matrix[index][0] > target) {
                max = index - 1;
            } else {
                min = index + 1;
            }
        }

        cout << "index is: " << index;

        min = 0;
        max = matrix[index].size() - 1;
        
        while (min <= max) {
            int mid = (min + max) / 2;

            if (matrix[index][mid] == target) {
                return true;
            } else if (matrix[index][mid] < target) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }

        return false;
    }
};
