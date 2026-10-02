class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        int max = nums.size() - k + 1;

        for (int i : nums) {
            heap.push(i);

            if (heap.size() > max) {
                heap.pop();
            }
        }

        return heap.top();
    }
};
