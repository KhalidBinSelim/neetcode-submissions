class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_set<int> st(nums.begin(), nums.end());
        int consecutive_cnt = 1, longest_consecutive_cnt = 1;
        for (int val: st) {
            if (st.find(val - 1) == st.end()) {
                consecutive_cnt = 1;
                while (st.find(val + consecutive_cnt) != st.end()) {
                    consecutive_cnt++;
                }
                longest_consecutive_cnt = max(longest_consecutive_cnt, consecutive_cnt);
            }
        }
        return longest_consecutive_cnt;
    }
};