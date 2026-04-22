class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            int cur = nums[i], l = i + 1, r = n - 1;
            while (l < r) {
                if (cur + nums[l] + nums[r] < 0) l++;
                else if (cur + nums[l] + nums[r] > 0) r--;
                else {
                    res.push_back({cur, nums[l], nums[r]});
                    l++, r--;
                    while (l < r and nums[l] == nums[l - 1]) l++;  
                }
            }
        }
        return res;
    }
};