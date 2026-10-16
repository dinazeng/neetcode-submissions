class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if (size == 0) return 0;
        if (size == 1) return heights[0];
        int max_area = 0;

        stack <pair<int, int>> st;
        for (int i = 0; i < size; i++) {
            int start = i;
            while (!st.empty() && heights[i] < st.top().first) {
                int index = st.top().second;
                int area = st.top().first * (i - index);
                st.pop();

                start = index;

                max_area = max(area, max_area);
            }

            st.push({heights[i], start});
        }

        while (!st.empty()) {
            int height = st.top().first;
            int index = st.top().second;
            st.pop();
            
            int area = (size - index) * height;
            max_area = max(area, max_area);
        }   

        return max_area;
    }
};
