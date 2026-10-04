class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> adj(numCourses);

        for (vector<int> v : prerequisites) {
            adj[v[0]].insert(v[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            stack<int> st;
            st.push(i);
            set<int> processed = {};
            while(!st.empty()) {
                int node = st.top();
                st.pop();

                for (int neighbour : adj[node]) {
                    if (neighbour == i) {
                        return false;
                    }

                    if (!processed.contains(neighbour)) {
                        st.push(neighbour);
                        processed.insert(neighbour);
                    }
                }
            }

            adj[i] = {};
        }

        return true;
    }
};