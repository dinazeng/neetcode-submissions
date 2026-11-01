class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (string t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int two = st.top();
                st.pop();
                
                int one = st.top();
                st.pop();

                if (t == "+" ) {
                    st.push(one + two);
                } else if (t == "-") {
                    st.push(one - two);
                } else if (t == "*") {
                    st.push(one * two);
                } else {
                    st.push(one / two);
                }
            } else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};
