class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;

        for (int n : stones) {
            heap.push(n);
        }

        while (heap.size() > 1) {
            int x = heap.top();
            heap.pop();

            int y = heap.top();
            heap.pop();

            if (x - y != 0) {
                heap.push(x - y);
            }
        }

        return heap.empty() ? 0 : heap.top();
    }
};
