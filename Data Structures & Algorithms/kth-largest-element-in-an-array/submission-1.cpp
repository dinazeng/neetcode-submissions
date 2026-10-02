class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;

        for (int i : nums) {
            heap.push(i);
        }

        int push_times = k - 1;

        while (push_times != 0) {
            heap.pop();
            push_times--;
        }

        return heap.top();
    }
};
