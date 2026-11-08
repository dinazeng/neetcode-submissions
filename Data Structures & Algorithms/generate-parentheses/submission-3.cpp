class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string curr;

        dfs(sol, curr, 0, 0, n);
        return sol;
    }

    void dfs (vector<string>& sol, string& curr, int l, int r, int& n) {
        if (2 * n == l + r) {
            sol.push_back(curr);
            return;
        }

        if (l < n) {
            curr += '(';
            dfs(sol, curr, l + 1, r, n);
            curr.pop_back();
        }

        if (r < l) {
            curr += ')';
            dfs(sol, curr, l, r + 1, n);
            curr.pop_back();
        }
    }
};
