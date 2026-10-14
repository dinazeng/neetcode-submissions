class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        int third = floor(size/3);
        map<int, int> freq;

        for (int n : nums) {
            freq[n]++;
        }

        vector<int> ret;

         for (auto& pair : freq) {
            if (pair.second > third) {
                ret.push_back(pair.first);
            }
        }

        return ret;
    }
};