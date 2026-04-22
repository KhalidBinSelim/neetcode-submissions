class Solution {
public:
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> memo;
        return dfs(nums, 0, memo);
    }
private:
    bool dfs(vector<int>& nums, int idx, unordered_map<int, bool>& memo) {
        if (memo.count(idx)) return memo[idx];
        if (idx == nums.size() - 1) return true;
        if (nums[idx] == 0) return false;
        int end = min(idx + nums[idx], (int)nums.size() - 1);
        for (int j = idx + 1; j <= end; j++) {
            if (dfs(nums, j, memo)) {
                memo[idx] = true;
                return true;
            }
        }
        memo[idx] = false;
        return false;
    }
};
