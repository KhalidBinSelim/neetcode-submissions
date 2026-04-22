class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), area = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int cur_area = min(height[i], height[j]) * (j - i);
                area = max(cur_area, area);
            }
        }
        return area;
    }
};