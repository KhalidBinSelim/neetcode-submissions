class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int prevIdx = 0;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= 1 and nums[i] == nums[i - 1]) idx = prevIdx;
            else idx = 0;
            prevIdx = res.size();
            for (int j = idx; j < prevIdx; j++) {
                vector<int> cur = res[j];
                cur.push_back(nums[i]);
                res.push_back(cur);
            }
        }
        return res;
    }
};
