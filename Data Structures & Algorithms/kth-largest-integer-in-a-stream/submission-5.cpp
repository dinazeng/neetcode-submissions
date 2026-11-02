class KthLargest {
public:
    int cap;
    priority_queue <int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());

        while (pq.size() > cap) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);

        if (pq.size() > cap) {
            pq.pop();
        }

        return pq.top();
    }
};
