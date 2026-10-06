class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char t : tasks) {
            count[t - 'A']++;
        }  

        priority_queue<int> pq;

        for (int c : count) {
            if (c > 0) {
                pq.push(c);
            }
        }

        pair<int, int> processNext;
        queue<pair<int, int>> nextQueue;
        int t = 0;
        while (!pq.empty() || !nextQueue.empty()) {
            t++;

            if (pq.empty()) {
                t = nextQueue.front().first;
            } else {
                int count = pq.top() - 1;
                pq.pop();

                if (count > 0) {
                    nextQueue.push({t + n, count});
                }
            }

            if (!nextQueue.empty() && nextQueue.front().first == t) {
                pq.push(nextQueue.front().second);       
                nextQueue.pop();       
            } 
            
        }

        return t;
    }
};
