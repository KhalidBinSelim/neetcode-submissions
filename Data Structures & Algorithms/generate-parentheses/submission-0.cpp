class Solution {
public:

    bool valid_par(const string &str) {
        int open_par_cnt = 0;
        for (int ch: str) { 
            if (ch == '(') open_par_cnt++;
            else open_par_cnt--;
            if (open_par_cnt < 0) return false;
        }
        return open_par_cnt == 0;
    }

    void dfs(string str, vector<string> &ans, int n) {
        if (str.size() == 2 * n) {
            if (valid_par(str)) ans.push_back(str);
            return;
        } 
        dfs(str + '(', ans, n);
        dfs(str + ')', ans, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs("", ans, n);
        return ans;
    }
};