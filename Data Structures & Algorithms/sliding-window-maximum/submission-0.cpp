class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<pair<int, int>> max_heap;
        vector<int> sol(size - k + 1);

        for (int i = 0; i < k; i++) {
            max_heap.push({nums[i], i});
        }

        sol[0] = max_heap.top().first;

        for (int i = 1; i <= size - k; i++) {
            max_heap.push({nums[i + k - 1], i + k - 1});
            while (!max_heap.empty() && max_heap.top().second < i) {
                max_heap.pop();
            }

            sol[i] = max_heap.top().first;
        }
        
        return sol;
    }
};
