class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();

        int sumTotal = 0;

        for (int n : nums) {
            sumTotal += n;
        }

        if (sumTotal % 2 == 1) {
            return false;
        }

        sumTotal /=2;
        
        if (sumTotal == nums[0]) {
            return true;
        }

        set<int> values = {nums[0]};

        for (int i = 1; i < size; i++) {
            set<int> temp = values;
            for (int n : temp) {
                int sum = nums[i] + n;

                cout << "sum: " << sum << endl;
                if (sum == sumTotal) {
                    return true;
                }

                values.insert(sum);
            }
        }

        return false;
    }
};
