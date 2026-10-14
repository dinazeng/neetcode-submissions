class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int half = ceil(size / 2);

        map<int, int> freq;

        for (int n : nums) {
            freq[n]++;

            if (freq[n] > half) {
                return n;
            }
        }
    }
};