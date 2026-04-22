class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cur_pref_sum = 0, cnt = 0;
        unordered_map<int,int> freq;
        freq[0] = 1;
        for (auto val: nums) {
            cur_pref_sum += val;
            int rem = cur_pref_sum - k;
            cnt += freq[rem];
            freq[cur_pref_sum]++;
        }
        return cnt;
    }
};