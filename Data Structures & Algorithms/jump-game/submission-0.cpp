class Solution {
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums, 0);
    }
private:
    bool dfs(vector<int>& nums, int idx) {
        if (idx == nums.size() - 1) return true;
        int end = min(idx + nums[idx], (int)nums.size() - 1);
        for (int j = idx + 1; j <= end; j++) {
            if (dfs(nums, j)) return true;
        }
        return false;
    }
};
