class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        dfs(0, s, partition);
        return res;
    }
    void dfs(int i, string &s, vector<string>& partition) {
        if (i >= s.size()) {
            res.push_back(partition);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (isPali(s, i, j)) {
                partition.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s, partition);
                partition.pop_back();
            }
        }
    }
    bool isPali(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};