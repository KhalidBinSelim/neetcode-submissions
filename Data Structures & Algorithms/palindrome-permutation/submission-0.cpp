class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c: s) freq[c]++;
        int odd_freq_cnt = 0;
        for (auto [x, y]: freq) {
            if (y & 1) {
                odd_freq_cnt++;
            }
        }
        return odd_freq_cnt <= 1;
    }
};
