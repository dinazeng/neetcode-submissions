class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> degree (numCourses);

        for (vector<int> p : prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
            degree[a]++;
        }   

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }


        vector<int> course_order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();

            course_order.push_back(course);

            for (int take_next : adj[course]) {
                degree[take_next]--;
                if (degree[take_next] == 0) {
                    q.push(take_next);
                }
            }
        }

        if (course_order.size() != numCourses) {
            return {};
        }

        return course_order;
    }
};
