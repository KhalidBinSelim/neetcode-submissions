class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.size(), nt = t.size();
        if (ns < nt or t.empty()) return "";
        unordered_map<char, int> freq_t, freq_s;
        for (auto ch: t) freq_t[ch]++;
        int min_len = INT_MAX, start_idx = -1;
        int l = 0, have = 0, need = freq_t.size();
        for (int r = 0; r < ns; r++) {
            freq_s[s[r]]++;
            if (freq_t.count(s[r]) and freq_s[s[r]] == freq_t[s[r]]) have++;
            while (have == need) {
                if ((r - l + 1) < min_len) {
                    min_len = r - l + 1;
                    start_idx = l;
                }
                freq_s[s[l]]--;
                if (freq_t.count(s[l]) and (freq_s[s[l]] < freq_t[s[l]])) have--;
                l++;
            }
        }
        return min_len == INT_MAX? "" : s.substr(start_idx, min_len);
    }
};