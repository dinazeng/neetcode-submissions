class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> pairs;

        pairs['}'] = '{';
        pairs[']'] = '[';
        pairs[')'] = '(';

        for (char c : s) {
            if (stk.empty() && (c == '}' ||  c == ')' ||  c == ']')) {
                return false;
            } else if (pairs.contains(c)) {
                if (stk.top() != pairs[c]) {
                    return false;
                }

                stk.pop();
            } else {
                stk.push(c);
            }
        }

        if (stk.empty()) {
            return true;
        }

        return false;
    }
};
