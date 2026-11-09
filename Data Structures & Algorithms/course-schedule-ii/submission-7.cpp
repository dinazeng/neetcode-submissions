class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) {
            return {};
        }

        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);

        for (const auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
            indegrees[a]++;
        }

        queue<int> q;
        vector<int> order(numCourses);
        int taken = 0;

        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
                order[taken++] = i;
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            for (const auto& nei : adj[course]) {
                indegrees[nei]--;
                
                if(indegrees[nei] == 0) {
                    order[taken++] = nei;
                    q.push(nei);
                }
            }
        }

        return taken == numCourses ? order : vector<int>();
    }
};
