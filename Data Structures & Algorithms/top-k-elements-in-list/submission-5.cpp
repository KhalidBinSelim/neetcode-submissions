class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> freq(nums.size() + 1);
        for (int num : nums) mp[num]++;
        for (auto [x, y]: mp) freq[y].push_back(x);
        vector<int> res;
        for (int i = freq.size() - 1; i >= 1; i--) {
            for (int num: freq[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};