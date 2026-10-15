class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> degrees(numCourses);

        for (vector<int> prereq : prerequisites) {
            int a = prereq[0];
            int b = prereq[1];

            adj[b].push_back(a);
            degrees[a]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                q.push(i);
            }
        }

        int courses = 0;

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            courses++;

            for (int p : adj[course]) {
                degrees[p]--;

                if (degrees[p] == 0) {
                    q.push(p);
                }
            }
        }

        return courses == numCourses;
    }
};
