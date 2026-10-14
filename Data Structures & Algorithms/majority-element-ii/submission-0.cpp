class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        int third = floor(size/3);
        map<int, int> freq;
        set<int> majority;

        for (int n : nums) {
            freq[n]++;

            if (freq[n] > third) {
                majority.insert(n);
            }
        }

        return vector<int> (majority.begin(), majority.end());
    }
};