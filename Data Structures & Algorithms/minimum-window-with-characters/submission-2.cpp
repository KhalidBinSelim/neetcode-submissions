class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (n == 0 or m < n) return "";
        vector<int> need(128, 0), window(128, 0);
        for (char c : t) need[c]++;
        int formed = 0, required = n;
        int l = 0, start = 0, minLen = INT_MAX;
        for (int r = 0; r < m; r++) {
            char c = s[r];
            window[c]++;
            if (need[c] > 0 and window[c] <= need[c]) formed++;
            while (formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                char c = s[l];
                window[c]--;
                if (need[c] > 0 and window[c] < need[c]) formed--;
                l++;
            }
        }
        return minLen == INT_MAX? "" : s.substr(start, minLen);
    }
};