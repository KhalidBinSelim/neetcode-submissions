class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.size(), nt = t.size();
        if (ns < nt or t.empty()) return "";
        unordered_map<char, int> freq_t;
        for (auto ch: t) freq_t[ch]++;
        int min_len = INT_MAX, start_idx = -1;
        for (int i = 0; i < ns; i++) {
            unordered_map<char, int> freq_s;
            for (int j = i; j < ns; j++) {
                freq_s[s[j]]++;
                bool ok = true;
                for (auto &[ch, freq]: freq_t) {
                    if (freq_s[ch] < freq) {
                        ok = false;
                        break;
                    }
                }
                if (ok and (j - i + 1) < min_len) {
                    min_len = min(min_len, j - i + 1);
                    start_idx = i; 
                }
            }
        }
        return min_len == INT_MAX? "" : s.substr(start_idx, min_len);
    }
};