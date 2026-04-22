class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
        for (auto &x: nums) {
            freq_map[x]++;
        }
        vector<pair<int,int>> freq_vector;
        for (auto &pr: freq_map) {
            freq_vector.push_back(pr);
        }
        sort(freq_vector.begin(), freq_vector.end(), [] (pair<int,int> &a, pair<int,int> &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        vector<int> ans_vector;
        for (auto [x,y]: freq_vector) {
            if (k == 0) {
                break;
            }
            ans_vector.push_back(x);
            k--;
        }
        return ans_vector;
    }
};