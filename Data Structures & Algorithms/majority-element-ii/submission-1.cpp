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

        auto it = freq.begin();
        while (it != freq.end()) {
            if (it->second > third) {
                ret.push_back(it->first);
            }
            it++;
        }


        return ret;
    }
};