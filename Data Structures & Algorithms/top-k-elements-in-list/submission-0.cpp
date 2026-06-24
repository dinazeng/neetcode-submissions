class Solution {
public:

    struct compareFunction {
        bool operator() (pair<int, int> const &a, pair<int, int> const &b) {
            
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;

        for (int i : nums) {
            freq[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, compareFunction> pq;

        for (auto p : freq) {
            pq.push(p);
        }

        vector<int> v(k);

        int i = 0;

        while (i < k) {
            v[i] = pq.top().first;
            pq.pop();

            i++;
        }

        return v;
    }
};
