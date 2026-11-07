class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> sol;

        dfs(0, 0, n, str, sol);

        return sol;
    }

    void dfs(int l, int r, int& n, string &str, vector<string>& sol) {
        if (str.length() == 2 * n) {
            sol.push_back(str);
        }

        if (l < n) {
            str += '(';
            dfs(l + 1, r, n, str, sol);
            str.pop_back();
        }

        if (r < l) {
            str += ')';
            dfs(l, r + 1, n, str, sol);
            str.pop_back();
        }
    }
};
