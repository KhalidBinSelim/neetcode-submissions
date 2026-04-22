class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int left_max = height[i], right_max = height[i];
            for (int j = 0; j < i; j++) left_max = max(left_max, height[j]);
            for (int j = i + 1; j < n; j++) right_max = max(right_max, height[j]);
            res += min(left_max, right_max) - height[i];
        }
        return res;
    }
};