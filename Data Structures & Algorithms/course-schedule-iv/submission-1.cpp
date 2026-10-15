class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_set<int>> adj (numCourses);
        vector<unordered_set<int>> isPre(numCourses);
        vector<int> degrees(numCourses);

        for (vector<int> pre : prerequisites) {
            adj[pre[0]].insert(pre[1]);
            degrees[pre[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front(); q.pop();
            for (int neighbour : adj[course]) {
                isPre[neighbour].insert(course);
                isPre[neighbour].insert(isPre[course].begin(), isPre[course].end());

                degrees[neighbour]--;
                if (degrees[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        
        int q_size = queries.size();
        vector<bool> results (q_size);
        for (int i = 0; i < q_size; i++) {
            results[i] = isPre[queries[i][1]].contains(queries[i][0]);
        }

        return results;
    }
};