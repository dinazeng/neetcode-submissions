class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if (size == 0) return 0;
        if (size == 1) return heights[0];

        int max_rectangle = 0;
        stack<pair<int, int>> st;

        for (int i = 0; i < size; i++) {
            int curr = heights[i];
            int start = i;
            while (!st.empty() && st.top().first > curr) {
                int curr_height = st.top().first;
                int curr_width = st.top().second;

                int curr_rectangle = (i - curr_width) * curr_height;
                start = curr_width;

                st.pop();

                max_rectangle = max(max_rectangle, curr_rectangle);
            }

            st.push({curr, start});
        }

        while (!st.empty()) {
            int curr_height = st.top().first;
            int curr_width = st.top().second;
            st.pop();

            int curr_rectangle = (size - curr_width) * curr_height;
            max_rectangle = max(max_rectangle, curr_rectangle);
        }

        return max_rectangle;
    }
};
