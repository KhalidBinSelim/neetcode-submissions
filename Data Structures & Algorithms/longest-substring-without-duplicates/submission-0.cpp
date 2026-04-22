class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<bool> freq(256, false);
        if (n == 0 or n == 1) return n;
        int l = 0, r = l + 1, max_len = 1;
        freq[s[l]] = true;
        while (r < n) {
            if (freq[s[r]]) {
                freq[s[l]] = false;
                l++;
            }
            else {
                freq[s[r]] = true;
                max_len = max(max_len, r - l + 1);
                r++;
            }
        }
        return max_len;
    }
};