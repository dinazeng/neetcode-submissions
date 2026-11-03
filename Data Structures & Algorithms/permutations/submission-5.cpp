class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return {};
        }

        vector<vector<int>> perms = {{nums[0]}};

        for (int i = 1; i < size; i++) {
            vector<vector<int>> temp;
            int n = nums[i];
            for (vector<int> v : perms) {
                int size_v = v.size();
                vector<int> t = v;
                for (int i = 0; i < size_v; i++) {
                    vector<int> t = v;
                    t.insert(t.begin() + i, n);
                    temp.push_back(t);
                }

                v.push_back(n);
                temp.push_back(v);
            }

            perms = temp;
        }

        return perms;
    }
};
