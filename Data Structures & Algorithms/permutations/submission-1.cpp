class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solutions = {{nums[0]}};
        
        for( int i = 1; i < nums.size(); i++) {
            permute(i, solutions, nums);
        }  

        return solutions;
    }

    void permute(int i, vector<vector<int>> &solutions, vector<int> &nums) {
        int size = solutions.size();
        vector<vector<int>> temp_sol;
        for (int j = 0; j < size; j++) {
            int size_subset = solutions[j].size();
            int to_insert = nums[i];
            for (int k = 0; k < size_subset; k++) {
                vector<int> subset = solutions[j];
                subset.insert(subset.begin() + k, to_insert);
                temp_sol.push_back(subset);
            }

            solutions[j].push_back(to_insert);
            temp_sol.push_back(solutions[j]);
        }

        solutions = temp_sol;
    }
};
