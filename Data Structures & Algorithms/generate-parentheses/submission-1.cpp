class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> solution;
        dfs(solution, str, 0, 0, n);

        return solution;
    }

    void dfs(vector<string> &solution, string &curr, int open, int close, int n){
        if (curr.size() == 2 * n) {
            solution.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            dfs(solution, curr, open + 1, close, n);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            dfs(solution, curr, open, close + 1, n);
            curr.pop_back();
        }
    }
};
