class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int min = 0;
        int max = numbers.size() - 1;

        while (min <= max) {
            int sum = numbers[min] + numbers[max];

            if (sum < target) {
                min++;
            } else if (sum > target) {
                max--;
            } else {
                return {min + 1, max + 1};
            }
        }

        return {};
    }
};
