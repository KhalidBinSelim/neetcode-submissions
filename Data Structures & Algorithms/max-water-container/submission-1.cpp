class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), area = 0;
        for (int i = 0, j = n - 1; i < j; ) {
            int cur_area = min(height[i], height[j]) * (j - i);
            area = max(cur_area, area);
            if (i < n and height[i] < height[j]) i++;
            else if (j >= 0 and height[i] >= height[j]) j--;
        }
        return area;
    }
};