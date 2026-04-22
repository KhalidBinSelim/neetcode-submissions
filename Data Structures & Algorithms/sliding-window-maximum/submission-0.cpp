class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i <= n - k; i++) {
            int cur_max = nums[i];
            for (int j = i; j < i + k; j++) {
                cur_max = max(cur_max, nums[j]);
            }
            res.push_back(cur_max);
        }
        return res;
    }
};