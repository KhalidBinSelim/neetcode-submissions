class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0, l = n + 1, r = -1;
        for (int i = 0; i < n; i++) {
            r = i + 1;
            while (r < n and heights[r] >= heights[i]) r++;
            l = i;
            while (l >= 0 and heights[l] >= heights[i]) l--;
            l++, r--;
            int area = (r - l + 1) * heights[i];
            max_area = max(area, max_area);
        }
        return max_area;
    }
};