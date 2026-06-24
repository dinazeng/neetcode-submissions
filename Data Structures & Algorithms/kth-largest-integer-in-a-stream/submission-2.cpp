class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    int max;

    KthLargest(int k, vector<int>& nums) {
        max = k;
        for (int n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        if (heap.size() < max) {
            heap.push(val);
        } else if (val > heap.top()) {
            heap.pop();

            heap.push(val);
        }

        return heap.top();
    }
};
