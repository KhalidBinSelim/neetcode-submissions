class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (auto x: nums) {
            freq[x]++;
        }
        vector<int> ans;
        for (auto [x,y]: freq) {
            if (y > nums.size() / 3) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};