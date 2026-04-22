class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int vector_length = strs.size();
        sort(strs.begin(), strs.end());
        string first_string = strs[0], last_string = strs[vector_length - 1];
        int minimum_comparison_length = first_string.size();
        for (int i = 0; i < minimum_comparison_length; i++) {
            if (first_string[i] == last_string[i]) {
                res += first_string[i];
            } else {
                break;
            }
        }
        return res;
    }
};