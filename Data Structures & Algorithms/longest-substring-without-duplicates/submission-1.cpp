class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0 or n == 1) return n;
        vector<bool> freq(256, false);
        int l = 0, r = l + 1, maxLen = 0;
        freq[s[l]] = true;
        while (r < n) {
            if (freq[s[r]]) {
                freq[s[l]] = false;
                l++;
            } else {
                freq[s[r]] = true;
                maxLen = max(maxLen, r - l + 1);
                r++;
            }
        }
        return maxLen;
    }
};