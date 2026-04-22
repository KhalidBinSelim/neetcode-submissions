class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        set<int> st;
        for (int val: nums) {
            st.insert(val);
        }
        vector<int> set_vector;
        for (int val: st) {
            set_vector.push_back(val);
        }
        int consecutive_cnt = 1, longest_consecutive_cnt = 1;
        for (int i = 1; i < set_vector.size(); i++) {
            if (set_vector[i] == set_vector[i - 1] + 1) {
                consecutive_cnt++;
            } else {
                longest_consecutive_cnt = max(longest_consecutive_cnt, consecutive_cnt);
                consecutive_cnt = 1;
            }
        }
        longest_consecutive_cnt = max(longest_consecutive_cnt, consecutive_cnt);
        return longest_consecutive_cnt;
    }
};