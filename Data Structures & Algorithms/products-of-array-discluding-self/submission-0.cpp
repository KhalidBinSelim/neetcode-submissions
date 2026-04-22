class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix_array[nums.size() + 1];
        prefix_array[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix_array[i] = prefix_array[i - 1] * nums[i];
        }
        int suffix_array[nums.size() + 1];
        suffix_array[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffix_array[i] = suffix_array[i + 1] * nums[i];
        }
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                ans[0] = suffix_array[1];
            } else if (i == nums.size() - 1) {
                ans[i] = prefix_array[i - 1];
            } else {
                ans[i] = prefix_array[i - 1] * suffix_array[i + 1];
            }
        }
        return ans;
    }
};