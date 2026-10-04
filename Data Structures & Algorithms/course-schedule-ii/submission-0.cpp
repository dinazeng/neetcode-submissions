class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degrees(numCourses, 0);
        vector<set<int>> adj(numCourses);
        
        for (vector<int> v : prerequisites) {
            in_degrees[v[0]]++;
            adj[v[1]].insert(v[0]);
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (in_degrees[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            order.push_back(top);

            for (int next : adj[top]) {
                in_degrees[next]--;
                if (in_degrees[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (order.size() != numCourses) {
            return {};
        }

        return order;
    }
};
