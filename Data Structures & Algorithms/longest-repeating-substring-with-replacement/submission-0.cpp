class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n == 0 or n == 1) return n;
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            int max_freq = 0;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;
                max_freq = max(max_freq, freq[s[j]]);
                if ((j - i + 1) - max_freq <= k) max_len = max(max_len, j - i + 1);
            }
        }
        return max_len;
    }
};