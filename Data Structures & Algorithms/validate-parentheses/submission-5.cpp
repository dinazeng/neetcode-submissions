class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        map<char, char> corres;
        corres['}'] = '{';
        corres[']'] = '[';
        corres[')'] = '(';

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }

                if (st.top() != corres[c]) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};
