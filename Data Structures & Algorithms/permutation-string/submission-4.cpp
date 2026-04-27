class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        vector<int> need(26, 0), window(26, 0);
        for (int i = 0; i < n; i++) {
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }
        if (need == window) return true;
        for (int r = n; r < m; r++) {
            window[s2[r] - 'a']++;
            window[s2[r - n] - 'a']--;
            if (need == window) return true;
        }
        return false;
    }
};