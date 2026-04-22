class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;
        sort(s1.begin(), s1.end());
        for (int i = 0; i < n2; i++) {
            for (int j = i; j < n2; j++) {
                string cur = s2.substr(i, j - i + 1);
                sort(cur.begin(), cur.end());
                if (cur == s1) return true;
            }
        }
        return false;
    }
};