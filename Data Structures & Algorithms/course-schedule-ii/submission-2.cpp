class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> adj (numCourses);
        vector<int> indegrees (numCourses, 0);

        for (vector<int> &prereq : prerequisites) {
            int a = prereq[0];
            int b = prereq[1];

            adj[b].insert(a);

            indegrees[a]++;
        }

        queue<int> q;

        for (int c = 0; c < numCourses; c++) {
            if (indegrees[c] == 0) {
                q.push(c);
            }
        }

        set<int> visited;
        vector<int> courseOrder;

        while (!q.empty()) {
            int course = q.front();

            visited.insert(course);
            courseOrder.push_back(course);

            q.pop();

            for (int canTakeNow : adj[course]) {
                if (visited.contains(canTakeNow)) {
                    return {};
                }

                indegrees[canTakeNow]--;
                if (indegrees[canTakeNow] == 0) {
                    q.push(canTakeNow);
                }
            }
        }
        
        if (courseOrder.size() != numCourses) {
            return {};
        }
        
        return courseOrder;
    }
};
