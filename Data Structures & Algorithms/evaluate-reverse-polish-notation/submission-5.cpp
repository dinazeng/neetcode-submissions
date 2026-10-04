class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int size = tokens.size();

        for (int i = 0; i < size; i++) {
            string t = tokens[i];
            if (t == "/") {
                int two = st.top();
                st.pop();
                int one = st.top();
                st.pop();
                st.push(one / two);
            } else if (t == "+") {
                int two = st.top();
                st.pop();
                int one = st.top();
                st.pop();
                st.push(one + two);
            } else if (t == "-") {
                int two = st.top();
                st.pop();
                int one = st.top();
                st.pop();
                st.push(one - two);
            } else if (t == "*") {
                int two = st.top();
                st.pop();
                int one = st.top();
                st.pop();
                st.push(one * two);
            } else {
                st.push(stoi(t));
            } 
        }
        

        return st.top();
    }
};
