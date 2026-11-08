class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if (size == 0) return 0;
        if (size == 1) return heights[0];

        int max_rect = 0;
        stack<pair<int,int>> st;

        for (int i = 0; i < size; i++) {
            int h = heights[i]; 
            int start = i;
            while (!st.empty() && st.top().first > h) {
                int width = i - st.top().second;
                start = st.top().second;
                max_rect = max(max_rect, width * st.top().first);
                st.pop();
            }

            st.push({heights[i], start});
        }

         while (!st.empty()) {
            int width = size - st.top().second;
            max_rect = max(max_rect, width * st.top().first);
            st.pop();
        }

        return max_rect;
    }
};
