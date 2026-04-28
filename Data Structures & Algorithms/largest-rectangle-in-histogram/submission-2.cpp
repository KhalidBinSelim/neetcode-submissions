class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int start = i;
            while (!st.empty() and heights[i] < st.top().second) {
                int idx = st.top().first, height = st.top().second;
                maxArea = max(maxArea, height * (i - idx));
                start = idx;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while (!st.empty()) {
            int idx = st.top().first, height = st.top().second;
            maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - idx));
            st.pop();
        }
        return maxArea;
    }
};