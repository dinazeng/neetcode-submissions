class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if (size == 0) return 0;
        if (size == 1) return heights[0];

        int max_area = 0;
        stack<pair<int, int>> st;

        for (int i = 0; i < size; i++) {
            int start = i;
            while (!st.empty() && st.top().first > heights[i]) {
                int curr_height = st.top().first;
                int curr_width = st.top().second;

                int curr_area = curr_height * (i - curr_width);
                max_area = max(max_area, curr_area);

                start = curr_width;

                st.pop();
            } 

            st.push({heights[i], start});
        }

        while (!st.empty()) {
            int curr_height = st.top().first;
            int curr_width = st.top().second;
            st.pop();

            int curr_area = curr_height * (size - curr_width);
            max_area = max(max_area, curr_area);
        }

        return max_area;
    }
};
