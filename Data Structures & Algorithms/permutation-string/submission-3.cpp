class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        unordered_map<char, int> freq1;
        for (char c : s1) freq1[c]++;
        int need = freq1.size();
        for (int i = 0; i < n2; i++) {
            unordered_map<char, int> freq2;
            int cur = 0;
            for (int j = i; j < n2; j++) {
                char c = s2[j];
                freq2[c]++;
                if (freq1[c] < freq2[c]) break;
                if (freq1[c] == freq2[c]) cur++;
                if (cur == need) return true;
            }
        }
        return false;
    }
};