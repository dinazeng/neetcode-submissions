class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string o : operations) {
            if (o == "+") {
                int one = st.top();
                st.pop();
                int two = st.top();
                st.pop();

                st.push(two);
                st.push(one);
                st.push(one + two);
            } else if (o == "D") {
                int double_this = st.top();
                st.push(double_this * 2);
            } else if (o == "C") {
                st.pop();
            } else {
                st.push(stoi(o));
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};