class Solution {
public:
    struct mycomp {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> q;
        unordered_map<int, int> freq;

        for (int n : nums) {
            freq[n]++;
        }

        for (auto p : freq) {
            q.push(p);
        }

        vector<int> results(k);
        int i = 0;

        while (i < k) {
            results[i] = q.top().first;

            q.pop();
            i++;
        }
        
        return results;
    }
};
