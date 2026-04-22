class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &v1 = nums1, &v2 = nums2;
        int total_size = v1.size() + v2.size();
        int half_size = (total_size + 1) / 2;
        if (v2.size() < v1.size()) swap(v1, v2);
        int l = 0, r = v1.size();
        while (l <= r) {
            int i = l + (r - l) / 2, j = half_size - i;
            int v1left, v1right, v2left, v2right;
            if (i > 0) v1left = v1[i - 1];
            else v1left = INT_MIN;
            if (i < v1.size()) v1right = v1[i];
            else v1right = INT_MAX;
            if (j > 0) v2left = v2[j - 1];
            else v2left = INT_MIN;
            if (j < v2.size()) v2right = v2[j];
            else v2right = INT_MAX;
            if (v1left <= v2right and v2left <= v1right) {
                if (total_size % 2 != 0) return max(v1left, v2left);
                return (max(v1left, v2left) + min(v1right, v2right)) / 2.0;
            } else if (v1left > v2right) r = i - 1;
            else l = i + 1;
        }
        return -1;
    }
};