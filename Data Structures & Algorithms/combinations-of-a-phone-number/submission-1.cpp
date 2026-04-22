class Solution {
public:
    vector<string> res = {""};
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        for (char digit: digits) {
            vector<string> cur;
            for (string &curStr: res) {
                for (char c: digitToChar[digit - '0']) {
                    cur.push_back(curStr + c);
                }
            }
            res = cur;
        }
        return res;
    }
};
