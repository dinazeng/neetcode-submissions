class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) {
            return true;
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
        int visited = 0;

        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
                visited++;
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            for (const auto& nei : adj[course]) {
                indegrees[nei]--;
                
                if(indegrees[nei] == 0) {
                    visited++;
                    q.push(nei);
                }
            }
        }

        return visited == numCourses;
    }
};
