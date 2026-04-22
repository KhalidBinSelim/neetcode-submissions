class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms = {{}};
        for (int val: nums) {
            vector<vector<int>> new_perms;
            for (const auto& p: perms) {
                for (int i = 0; i <= p.size(); i++) {
                    vector<int> q = p;
                    q.insert(q.begin() + i, val);
                    new_perms.push_back(q);
                }
            }
            perms = new_perms;
        }
        return perms;
    }
};
