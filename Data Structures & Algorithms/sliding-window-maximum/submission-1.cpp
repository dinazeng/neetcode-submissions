class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<pair<int, int>> max_heap;

        for (int i = 0; i < k; i++) {
            max_heap.push({nums[i], i});
        }

        vector<int> sol(size - k + 1);
        sol[0] = max_heap.top().first;

        for(int i = k; i < size; i++) {
            max_heap.push({nums[i], i});
            while (max_heap.top().second < i - k + 1) {
                max_heap.pop();
            }

            sol[i - k + 1] = max_heap.top().first;
        }

        return sol;
    }
};
