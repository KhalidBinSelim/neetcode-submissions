class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto [x, y]: mp) {
            minHeap.push({y, x});
            if (minHeap.size() > k) minHeap.pop();
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};