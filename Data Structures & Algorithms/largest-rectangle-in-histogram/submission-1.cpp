class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() and (i == n or heights[i] <= heights[st.top()])) {
                int top_h = heights[st.top()];
                st.pop();
                int cur_width;
                if (st.empty()) cur_width = i;
                else cur_width = i - st.top() - 1;
                max_area = max(max_area, top_h * cur_width);
            }
            st.push(i);
        }
        return max_area;
    }
};