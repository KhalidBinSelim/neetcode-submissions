class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;
        vector<pair<int, int>> pr;
        for (auto [x, y]: mp) pr.push_back({y, x});
        sort(pr.rbegin(), pr.rend());
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(pr[i].second);
        return res;
    }
};