class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        generateSubsets(candidates, target, 0, cur, 0);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void generateSubsets(vector<int>& candidates, int target, int i, vector<int>& cur, int total) {
        if (total == target) {
            res.insert(cur);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            if (j > i and candidates[j] == candidates[j - 1]) continue;
            if (total + candidates[j] > target) break;
            cur.push_back(candidates[j]);
            generateSubsets(candidates, target, j + 1, cur, total + candidates[j]);
            cur.pop_back();
        }
    }
};
