class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) {
            return {{}};
        }

        vector<int> next = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>>perms = permute(next);

        int n = nums[0];
        vector<vector<int>> results;
        for (vector<int> v : perms) {
            int size = v.size();
            for (int i = 0; i < size; i++) {
                vector<int> copy = vector<int>(v.begin(), v.end());
                copy.insert(copy.begin() + i, n);
                results.push_back(copy);
            }

            v.push_back(n);
            results.push_back(v);
        }

        return results;
    }

};
