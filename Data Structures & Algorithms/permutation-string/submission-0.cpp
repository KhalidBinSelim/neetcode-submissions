class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;
        unordered_map<char, int> freq1;
        for (int i = 0; i < n1; i++) freq1[s1[i]]++;
        int max_match_cnt = freq1.size();
        for (int i = 0; i < n2; i++) {
            int match_cnt = 0;
            unordered_map<char, int> freq2;
            for (int j = i; j < n2; j++) {      
                freq2[s2[j]]++;
                if (freq1[s2[j]] < freq2[s2[j]]) break;
                if (freq1[s2[j]] == freq2[s2[j]]) match_cnt++;
                if (match_cnt == max_match_cnt) return true;
            }
        }
        return false;
    }
};