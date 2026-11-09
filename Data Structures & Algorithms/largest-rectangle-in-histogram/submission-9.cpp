class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if (size == 0) return 0;
        if (size == 1) return heights[0];

        stack<pair<int, int>> st;
        int max_area = 0;

        for (int i = 0; i < size; i++) {
            int h = heights[i];
            int start = i;

            while (!st.empty() && st.top().first > h) {
                start = st.top().second;

                max_area = max(max_area, (i - start) * st.top().first);

                st.pop();
            }

            st.push({h, start});
        }

        while (!st.empty()) {
            max_area = max(max_area, (size - st.top().second) * st.top().first);
            st.pop();
        }

        return max_area;
    }
};
