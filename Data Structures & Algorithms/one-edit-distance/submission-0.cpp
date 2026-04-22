class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s == t) return false;
        int m = s.size(), n = t.size();
        if (abs(m - n) > 1) return false;
        int edit_cnt = 0;
        int i = 0, j = 0;
        while(i < m and j < n) {
            if (s[i] != t[j]) {
                if (edit_cnt == 1) return false;
                if (m > n) i++;
                else if (m < n) j++;
                else {
                    i++;
                    j++;
                }
                edit_cnt++;
            } else {
                i++;
                j++;
            }
        }
        if (i < m or j < n) {
            edit_cnt++;
        }
        return edit_cnt <= 1;
    }
};
