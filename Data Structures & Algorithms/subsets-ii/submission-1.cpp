class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, {});
        return res;
    }
    void backtrack(vector<int>& nums, int i, vector<int> subset) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums, i + 1, subset);
        subset.pop_back();
        while(i + 1 < nums.size() and nums[i] == nums[i + 1]) i++;
        backtrack(nums, i + 1, subset);
    }
};
