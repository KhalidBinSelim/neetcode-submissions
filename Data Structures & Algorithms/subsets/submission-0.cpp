class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int x: nums) {
            int cur_size = res.size();
            for (int i = 0; i < cur_size; i++) {
                vector<int> subset = res[i];
                subset.push_back(x);
                res.push_back(subset);
            }
        }
        return res;
    }
};
