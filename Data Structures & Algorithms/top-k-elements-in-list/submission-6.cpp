class Solution {
public:
    struct myComp {
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;

        for (int n : nums) {
            freq[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;

        for (auto &p : freq) {
            pq.push(p);
        }

        vector<int> sol(k);
        int i = 0;
        while (i < k) {
            sol[i] = pq.top().first;
            pq.pop();
            i++;
        }
        

        return sol;
    }
};
