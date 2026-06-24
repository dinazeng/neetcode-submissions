class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char c : s) {
            if (stk.empty() && (c == '}' ||  c == ')' ||  c == ']')) {
                return false;
            } else if (c == '}') {
                if (stk.top() != '{') {
                    return false;
                }

                stk.pop();
            } else if (c == ')') {
                if (stk.top() != '(') {
                    return false;
                }

                stk.pop();
            } else if (c == ']') {
                if (stk.top() != '[') {
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
