class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> adj(numCourses);

        for (vector<int> v : prerequisites) {
            adj[v[0]].insert(v[1]);
        }

        set<int> processed;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, processed, adj)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int i, set<int>& processed, vector<set<int>> &prereqs) {
        if (processed.contains(i)) {
            return false;
        }

        if(prereqs[i].empty()) {
            return true;
        }

        processed.insert(i);

        for(int c : prereqs[i]) {
            if (!dfs(c, processed, prereqs)) {
                return false;
            }
        }

        processed.erase(i);
        prereqs[i] = {};
        return true;
    }
};
