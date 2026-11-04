class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0 || prerequisites.size() == 0) {
            return true;
        }

        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);
        for (const vector<int> &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            
            indegrees[p[0]]++;
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

            for (const int &c : adj[course]) {
                indegrees[c]--;
                if (indegrees[c] == 0) {
                    q.push(c);
                    visited++;
                }
            }
        }

        return visited == numCourses;
    }
};
