class Solution {
public:

    void backtrack(int open, int close, int n, string &st, vector<string> & ans) {
        if (open == close and open == n) {
            ans.push_back(st);
            return;
        }
        if (open < n) {
            st += '(';
            backtrack(open + 1, close, n, st, ans);
            st.pop_back();
        }
        if (close < open) {
            st += ')';
            backtrack(open, close + 1, n, st, ans);
            st.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st;
        backtrack(0, 0, n, st, ans);
        return ans;
    }
};