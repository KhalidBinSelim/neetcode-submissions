class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
        for (auto &x: nums) {
            freq_map[x]++;
        }
        vector<pair<int,int>> freq_vector;
        for (auto &[x,y]: freq_map) {
            freq_vector.push_back({y,x});
        }
        sort(freq_vector.rbegin(), freq_vector.rend());
        vector<int> ans_vector;
        for (auto [x,y]: freq_vector) {
            if (k == 0) {
                break;
            }
            ans_vector.push_back(y);
            k--;
        }
        return ans_vector;
    }
};