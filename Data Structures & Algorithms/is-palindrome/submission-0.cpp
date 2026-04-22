class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for (auto c: s) if (isalnum(c)) res += tolower(c);
        if (res == string(res.rbegin(), res.rend())) return true;
        return false;
    }
};
