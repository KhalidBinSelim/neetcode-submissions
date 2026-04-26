class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(256, 0);
        int l = 0, r = l + 1, maxFreq = 0, maxLen = 0;
        freq[s[l]] = 1;
        while (r < n) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            if ((r - l + 1) - maxFreq > k) {
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};