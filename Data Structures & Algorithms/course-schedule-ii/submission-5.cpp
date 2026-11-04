class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);
        for (const vector<int> &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            
            indegrees[p[0]]++;
        }

        queue<int> q;
        vector<int> visited;

        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
                visited.push_back(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            for (const int &c : adj[course]) {
                indegrees[c]--;
                if (indegrees[c] == 0) {
                    q.push(c);
                    visited.push_back(c);
                }
            }
        }

        return visited.size() == numCourses ? visited : vector<int>();
    }
};
