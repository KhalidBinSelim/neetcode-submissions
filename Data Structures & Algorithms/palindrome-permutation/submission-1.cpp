class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> freq;
        int odd_cnt = 0;
        for (char c: s) {
            freq[c]++;
            if (freq[c] % 2 == 0) {
                odd_cnt--;
            } else {
                odd_cnt++;
            }
        }
        return odd_cnt <= 1;
    }
};
